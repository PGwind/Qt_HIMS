#include "../include/sparkchain.h"
#include <iostream>
#include <string>
#include <atomic>
#include <pthread.h> 
#include <unistd.h>
#include <regex>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

using namespace SparkChain;
using namespace std;

static atomic_bool finish(false);
string final_result = "";

class SparkCallbacks : public LLMCallbacks
{
    void onLLMResult(LLMResult *result, void *usrContext)
    {
        int status = result->getStatus();
        printf(GREEN "%d:%s:%s:%s \n" RESET, status, result->getRole(), result->getContent(), usrContext);
        final_result += string(result->getContent());
        if (status == 2)
        {
            printf(GREEN "tokens:%d + %d = %d\n" RESET, result->getCompletionTokens(), result->getPromptTokens(), result->getTotalTokens());
            finish = true;
        }
    }

    void onLLMEvent(LLMEvent *event, void *usrContext)
    {
        printf(YELLOW "onLLMEventCB\n  eventID:%d eventMsg:%s\n" RESET, event->getEventID(), event->getEventMsg());
    }

    void onLLMError(LLMError *error, void *usrContext)
    {
        printf(RED "onLLMErrorCB\n errCode:%d errMsg:%s \n" RESET, error->getErrCode(), error->getErrMsg());
        finish = true;
    }
};

int initSDK()
{
    // 全局初始化
    SparkChainConfig *config = SparkChainConfig::builder();
    config->appID("")
        ->apiKey("")
        ->apiSecret("")
        ->logLevel(0)
        ->logPath("./aikit.log");
    int ret = SparkChain::init(config);
    printf(RED "\ninit SparkChain result:%d" RESET, ret);
    return ret;
}

void *syncLLMThread(void *clientSocket)
{
    int serverSocket = *((int *)clientSocket);
    cout << "\n######### Listening for Qt messages #########" << endl;

    // 配置大模型参数
    LLMConfig *llmConfig = LLMConfig::builder();
    llmConfig->domain("generalv3");
    llmConfig->url("ws(s)://spark-api.xf-yun.com/v3.1/chat");

    Memory *window_memory = Memory::WindowMemory(5);
    LLM *syncllm = LLM::create(llmConfig, window_memory);

    char input[256];
    while (true)
    {
        memset(input, 0, sizeof(input));
        int bytesRead = recv(serverSocket, input, sizeof(input), 0);
        if (bytesRead <= 0)
        {
            break;
        }

        string qtMessage = input;
        printf("Received message from Qt: %s\n", qtMessage.c_str());

        LLMSyncOutput *result = syncllm->run(qtMessage.c_str());
        if (result->getErrCode() != 0)
        {
            printf(RED "\nsyncOutput: %d:%s\n\n" RESET, result->getErrCode(), result->getErrMsg());
        }
        else
        {
            string reply = result->getContent();
            printf(GREEN "\nsyncOutput: %s\n" RESET, reply.c_str());
            send(serverSocket, reply.c_str(), reply.size(), 0);
        }
    }

    if (syncllm != nullptr)
    {
        LLM::destroy(syncllm);
    }

    close(serverSocket);
    pthread_exit(NULL);
}

void uninitSDK()
{
    // 全局逆初始化
    SparkChain::unInit();
}

int main(int argc, char const *argv[])
{
    cout << "\n######### llm Start #########" << endl;
    // 全局初始化
    int ret = initSDK();
    if (ret != 0)
    {
        cout << "initSDK failed:" << ret << endl;
        return -1;
    }

    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    // 创建套接字
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("绑定错误");
        return -1;
    }

    // 初始化服务器
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1024);       
    serverAddr.sin_addr.s_addr = INADDR_ANY; 

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 绑定套接字
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("绑定错误");
        close(serverSocket);
        return -1;
    }

    // 监听传入连接
    if (listen(serverSocket, 128) < 0) // 允许128个同时连接
    {
        perror("Error in listen");
        return -1;
    }

    cout << "Listening for connections..." << endl;

    while (true)
    {
        int clientSocket;
        struct sockaddr_in clientAddr;
        clientAddrLen = sizeof(clientAddr);

        // 接受传入连接
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket < 0)
        {
            perror("Error in accept");
            continue;
        }

        // 创建一个线程来处理客户端连接
        pthread_t tid;
        int *socketPtr = new int(clientSocket);
        pthread_create(&tid, NULL, syncLLMThread, socketPtr);
    }

    // 退出
    uninitSDK();
    return 0;
}

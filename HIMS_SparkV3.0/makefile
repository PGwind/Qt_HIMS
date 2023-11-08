CC = g++
CFLAGS = -Iinclude
LIBS = -lSparkChain -lstdc++ -lpthread
SRC = src/server.cpp
OUTPUT = llm_server

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(OUTPUT)


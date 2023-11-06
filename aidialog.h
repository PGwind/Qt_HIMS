#ifndef AIDIALOG_H
#define AIDIALOG_H

#include <QDialog>
#include <QThread>
#include <QTcpSocket>
#include <QIcon>

namespace Ui {
class AiDialog;
}

class AiDialog : public QDialog
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QThread *connectionThread;

    void InitThread();
    void Init();
    void connectToServer();

public:
    explicit AiDialog(QWidget *parent = nullptr);
    ~AiDialog();

private slots:
    void onReadyRead();

    void onConnected();

    void sendToServer();

private:
    Ui::AiDialog *ui;
};

#endif // AIDIALOG_H

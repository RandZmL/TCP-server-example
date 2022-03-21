#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QFile>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    ~MyServer();

    QTcpSocket *socket;
    QByteArray Data;

    QJsonDocument doc;
    QJsonParseError docError;

public slots:
    void startServer();
    void incomingConnection(long long socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H

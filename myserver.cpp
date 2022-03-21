#include "myserver.h"

MyServer::MyServer()
{

}

MyServer::~MyServer()
{

}

void MyServer::startServer()
{
    if(this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Listening...";
    }
    else
    {
        qDebug() << "Failed to connect!";
    }
}

void MyServer::incomingConnection(long long socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

    qDebug() << "Client " << socketDescriptor << " connected!";

    socket->write("You are connected!");
    socket->write("{\"type\":\"connect\",\"status\":\"yes\"}");
    qDebug() << "Client status: connected";
}

void MyServer::sockReady()
{
    Data = socket->readAll();
    qDebug() << "Data: " << Data;

    doc = QJsonDocument::fromJson(Data, &docError);

    if (docError.errorString() == "no error occurred")
    {
        if ((doc.object().value("type").toString() == "select") && (doc.object().value("params").toString() == "workers"))
        {
            QFile file;
            file.setFileName("C:\\workers.json");
            if (file.open(QIODevice::ReadOnly|QFile::Text))
            {
                QByteArray fromFile = file.readAll();
                QByteArray summary = "{\"type\":\"resultSelect\",\"result\":" + fromFile + "}";

                socket->write(summary);
                socket->waitForBytesWritten(500);
            }

            file.close();
        }
    }
}

void MyServer::sockDisc()
{
    qDebug()<< "Disconnected";
    socket->deleteLater();
}




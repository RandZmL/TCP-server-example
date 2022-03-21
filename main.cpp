#include <QCoreApplication>
#include "myserver.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread Thread1;
    Thread1.name = "Thread_1";

    thread Thread2;
    Thread2.name = "Thread_2";

    thread Thread3;
    Thread3.name = "Thread_3";

    MyServer server;

    server.startServer();
    Thread1.start();
    Thread2.start();
    Thread3.start();

    return a.exec();
}

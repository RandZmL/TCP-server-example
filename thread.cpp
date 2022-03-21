#include "thread.h"
#include <QDebug>
thread::thread()
{

}

void thread::run()
{

    for (int i = 0; i < 2022; i++)
    {
        qDebug() << this->name << i;
    }
}

//Есть смысл вставлять этот кусочек кода?

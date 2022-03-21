#ifndef THREAD_H
#define THREAD_H
#include <QtCore>

class thread : public QThread
{
public:
    thread();
    void run(); //Запуск потока
    QString name; //Название потока
};

#endif // THREAD_H

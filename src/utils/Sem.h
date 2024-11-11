//
// Created by crab on 2024/10/28.
//

#ifndef SEM_H
#define SEM_H

#include <semaphore.h>

//封装信号量类semaphore

class Sem
{
public:
    static Sem* createNew(int val);

    Sem(int val);
    ~Sem();

    void post();
    void wait();

private:
    sem_t mSem;
};


#endif //SEM_H

//
// Created by crab on 2024/11/6.
//

#ifndef USAGEENVIRONMENT_H
#define USAGEENVIRONMENT_H

#include "EventScheduler.h"
#include "ThreadPool.h"

class UsageEnvironment
{
public:
    static UsageEnvironment* createNew(EventScheduler* scheduler, ThreadPool* threadPool);

    UsageEnvironment(EventScheduler* scheduler, ThreadPool* threadPool);
    ~UsageEnvironment();

    EventScheduler* scheduler();
    ThreadPool* threadPool();

private:
    EventScheduler* mScheduler;
    ThreadPool* mThreadPool;
};

#endif //USAGEENVIRONMENT_H

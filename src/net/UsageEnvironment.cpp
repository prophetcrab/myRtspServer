//
// Created by crab on 2024/11/6.
//

#include "UsageEnvironment.h"

#include <cstdio>
#include "New.h"

UsageEnvironment* UsageEnvironment::createNew(EventScheduler* scheduler, ThreadPool* threadPool)
{
    if(!scheduler)
        return NULL;

    //return new UsageEnvironment(scheduler, threadPool);
    return New<UsageEnvironment>::allocate(scheduler, threadPool);
}

UsageEnvironment::UsageEnvironment(EventScheduler* scheduler, ThreadPool* threadPool) :
    mScheduler(scheduler),
    mThreadPool(threadPool)
{

}

UsageEnvironment::~UsageEnvironment()
{

}

EventScheduler* UsageEnvironment::scheduler()
{
    return mScheduler;
}

ThreadPool* UsageEnvironment::threadPool()
{
    return mThreadPool;
}

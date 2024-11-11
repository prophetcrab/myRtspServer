//
// Created by crab on 2024/10/31.
//

#ifndef EVENTSCHEDULER_H
#define EVENTSCHEDULER_H

#include <vector>
#include <queue>

#include "PollPoller.h"
#include "Timer.h"
#include "Mutex.h"


class EventScheduler
{
public:
    typedef void (*Callback)(void*);

    enum PollerType
    {
        POLLER_SELECT,
        POLLER_POLL,
        POLLER_EPOLL
    };

    static EventScheduler* createNew(PollerType type);

    EventScheduler(PollerType type, int fd);
    virtual ~EventScheduler();

    bool addTriggerEvent(TriggerEvent* event);
    Timer::TimerId addTimedEventRunAfater(TimerEvent* event, Timer::TimeInterval delay);
    Timer::TimerId addTimedEventRunAt(TimerEvent* event, Timer::Timestamp when);
    Timer::TimerId addTimedEventRunEvery(TimerEvent* event, Timer::TimeInterval interval);
    bool removeTimedEvent(Timer::TimerId timerId);
    bool addIOEvent(IOEvent* event);
    bool updateIOEvent(IOEvent* event);
    bool removeIOEvent(IOEvent* event);

    void loop();
    void wakeup();

    void runInLocalThread(Callback callBack, void* arg);
    void handleOtherEvent();

private:
    void handleTriggerEvents();
    static void handleReadCallback(void*);
    void handleRead();

private:
    bool mQuit;
    Poller* mPoller;
    TimerManager* mTimerManager;
    std::vector<TriggerEvent*> mTriggerEvents;
    int mWakeupFd;
    IOEvent* mWakeIOEvent;

    std::queue<std::pair<Callback, void*> > mCallBackQueue;
    Mutex* mMutex;
};


#endif //EVENTSCHEDULER_H

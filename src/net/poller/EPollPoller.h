//
// Created by crab on 2024/10/29.
//

#ifndef EPOLLPOLLER_H
#define EPOLLPOLLER_H

#include <sys/epoll.h>
#include <vector>

#include "Poller.h"


class EPollPoller : public Poller
{
public:
    static EPollPoller* createNew();

    EPollPoller();
    virtual ~EPollPoller();

    virtual bool addIOEvent(IOEvent* event);
    virtual bool updateIOEvent(IOEvent* event);
    virtual bool removeIOEvent(IOEvent* event);
    virtual void handleEvent();

private:
    int mEPollFd;

    typedef std::vector<struct epoll_event> EPollEventList;
    EPollEventList mEPollEventList;
    std::vector<IOEvent*> mEvents;
};

#endif //EPOLLPOLLER_H

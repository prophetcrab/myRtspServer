//
// Created by crab on 2024/10/29.
//

#ifndef POLLER_H
#define POLLER_H

#include<map>
#include "Event.h"

class Poller
{
public:
    virtual ~Poller();

    virtual bool addIOEvent(IOEvent* event) = 0;
    virtual bool updateIOEvent(IOEvent* event) = 0;
    virtual bool removeIOEvent(IOEvent* event) = 0;
    virtual void handleEvent() = 0;

protected:
    Poller();

protected:
    typedef std::map<int, IOEvent*> IOEventMap;
    IOEventMap mEventMap;
};

#endif //POLLER_H

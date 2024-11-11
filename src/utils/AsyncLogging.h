//
// Created by crab on 2024/10/28.
//

#ifndef ASYNCLOGGING_H
#define ASYNCLOGGING_H

#include <string>
#include <queue>
#include <cstring>

#include "Thread.h"
#include "Mutex.h"
#include "Condition.h"

//缓冲区类，用来储存日志数据
class LogBuffer
{
public:
    LogBuffer() :
        mCurPtr(mData)
    { }

    ~LogBuffer()
    { }

    void append(const char* buf, size_t len)
    {
        if (avail() > len)
        {
            memcpy(mCurPtr, buf, len);
            mCurPtr += len;
        }
    }

    const char* data() const { return mData; }
    int length() const { return (int)(mCurPtr - mData); }

    char* current() { return mCurPtr; }
    int avail() const { return (int)(end() - mCurPtr); }
    void add(int len) { mCurPtr += len; }

    void reset() { mCurPtr = mData; }
    void bzero() { memset(mData, 0, BUFFER_SIZE); }

private:
    enum
    {
        BUFFER_SIZE = 1024*1024,
    };

    const char* end() const { return mData + BUFFER_SIZE; }

private:
    char mData[BUFFER_SIZE];
    char* mCurPtr;
};

class AsyncLogging : public Thread
{
public:
    virtual ~AsyncLogging();

    static AsyncLogging* instance();

    void append(const char* logline, int len);

protected:
    AsyncLogging(std::string file);
    virtual void run(void *arg);

private:
    enum
    {
        BUFFER_NUM = 4,
    };

    Mutex* mMutex;
    Condition* mCond;
    std::string mFile;
    FILE* mFp;
    bool mRun;

    LogBuffer mBuffer[BUFFER_NUM];
    LogBuffer* mCurBuffer;
    std::queue<LogBuffer*> mFreeBuffer;
    std::queue<LogBuffer*> mFlushBuffer;

    static AsyncLogging* mAsyncLogging;
};


#endif //ASYNCLOGGING_H

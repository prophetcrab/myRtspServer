//
// Created by crab on 2024/11/8.
//

#ifndef H264FILEMEDIASOURCE_H
#define H264FILEMEDIASOURCE_H


#include <string>

#include "UsageEnvironment.h"
#include "MediaSource.h"
#include "ThreadPool.h"

class H264FileMediaSource : public MediaSource
{
public:
    static H264FileMediaSource* createNew(UsageEnvironment* env, std::string file);

    H264FileMediaSource(UsageEnvironment* env, const std::string& file);
    ~H264FileMediaSource();

protected:
    virtual void readFrame();

private:
    int getFrameFromH264File(int fd, uint8_t* frame, int size);

private:
    std::string mFile;
    int mFd;
};

#endif //H264FILEMEDIASOURCE_H

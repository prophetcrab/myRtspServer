#include <iostream>
#include <unistd.h>
#include <chrono>
#include <vector>
#include <thread>

#include "src/utils/Logging.h"
#include "src/net/UsageEnvironment.h"
#include "src/utils/ThreadPool.h"
#include "src/net/EventScheduler.h"
#include "src/net/Event.h"
#include "src/net/RtspServer.h"
#include "src/net/MediaSession.h"
#include "src/net/InetAddress.h"
#include "src/net/H264FileMediaSource.h"
#include "src/net/H264RtpSink.h"


int main(int argc, char* argv[])
{
    if(argc !=  2)
    {
        std::cout<<"Usage: "<<argv[0]<<" <h264 file>"<<std::endl;
        return -1;
    }

    //Logger::setLogFile("xxx.log");
    Logger::setLogLevel(Logger::LogWarning);

    EventScheduler* scheduler = EventScheduler::createNew(EventScheduler::POLLER_SELECT);
    ThreadPool* threadPool = ThreadPool::createNew(2);
    UsageEnvironment* env = UsageEnvironment::createNew(scheduler, threadPool);

    Ipv4Address ipAddr("0.0.0.0", 8554);
    RtspServer* server = RtspServer::createNew(env, ipAddr);
    MediaSession* session = MediaSession::createNew("live");
    MediaSource* mediaSource = H264FileMediaSource::createNew(env, argv[1]);
    RtpSink* rtpSink = H264RtpSink::createNew(env, mediaSource);

    session->addRtpSink(MediaSession::TrackId0, rtpSink);
    //session->startMulticast(); //多播

    server->addMeidaSession(session);
    server->start();

    std::cout<<"Play the media using the URL \""<<server->getUrl(session)<<"\""<<std::endl;

    env->scheduler()->loop();

    return 0;
}
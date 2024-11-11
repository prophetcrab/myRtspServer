cmake_minimum_required(VERSION 3.16)
project(WebServer)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/src/net)
include_directories(${CMAKE_SOURCE_DIR}/src/net/poller)

add_executable(WebServer main.cpp
        src/utils/Thread.cpp
        src/utils/Thread.h
        src/utils/Mutex.cpp
        src/utils/Mutex.h
        src/utils/Condition.cpp
        src/utils/Condition.h
        src/utils/Allocator.cpp
        src/utils/Allocator.h
        src/utils/AsyncLogging.cpp
        src/utils/AsyncLogging.h
        src/utils/Logging.cpp
        src/utils/Logging.h
        src/utils/Sem.cpp
        src/utils/Sem.h
        src/utils/ThreadPool.cpp
        src/utils/ThreadPool.h
        src/utils/New.h
        src/utils/Construct.h
        src/net/poller/Poller.cpp
        src/net/poller/Poller.h
        src/net/poller/PollPoller.cpp
        src/net/poller/PollPoller.h
        src/net/poller/EPollPoller.cpp
        src/net/poller/EPollPoller.h
        src/net/poller/SelectPoller.cpp
        src/net/poller/SelectPoller.h
        src/net/Event.cpp
        src/net/Event.h
        src/net/Timer.cpp
        src/net/Timer.h
        src/net/EventScheduler.cpp
        src/net/EventScheduler.h
        src/net/SocketsOps.cpp
        src/net/SocketsOps.h
        src/net/UsageEnvironment.cpp
        src/net/UsageEnvironment.h
        src/net/InetAddress.cpp
        src/net/InetAddress.h
        src/net/Rtp.h
        src/net/RtpInstance.h
        src/net/MediaSource.cpp
        src/net/MediaSource.h
        src/net/MediaSession.cpp
        src/net/MediaSession.h
        src/net/H264FileMediaSource.cpp
        src/net/H264FileMediaSource.h
        src/net/Acceptor.cpp
        src/net/Acceptor.h
        src/net/AACRtpSink.cpp
        src/net/AACRtpSink.h
        src/net/AACFileMeidaSource.cpp
        src/net/AACFileMeidaSource.h
        src/net/Buffer.cpp
        src/net/Buffer.h
        src/net/H264RtpSink.cpp
        src/net/H264RtpSink.h
        src/net/RtpSink.cpp
        src/net/RtpSink.h
        src/net/RtspConnection.cpp
        src/net/RtspConnection.h
        src/net/RtspServer.cpp
        src/net/RtspServer.h
        src/net/TcpConnection.cpp
        src/net/TcpConnection.h
        src/net/TcpSocket.cpp
        src/net/TcpSocket.h
        src/net/TcpServer.cpp
        src/net/TcpServer.h
)


target_link_libraries(WebServer PRIVATE pthread)
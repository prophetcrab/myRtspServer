//
// Created by crab on 2024/11/8.
//

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <map>
#include "Acceptor.h"
#include "UsageEnvironment.h"
#include "InetAddress.h"
#include "TcpConnection.h"


class TcpServer
{
public:
    virtual ~TcpServer();

    void start();

protected:
    TcpServer(UsageEnvironment* env, const Ipv4Address& addr);
    virtual void handleNewConnection(int connfd) = 0;
    //virtual void handleDisconnection(int sockfd);

private:
    static void newConnectionCallback(void* arg, int connfd);
    //static void disconnectionCallback(void* arg, int sockfd);

protected:
    UsageEnvironment* mEnv;
    Acceptor* mAcceptor;
    Ipv4Address mAddr;
    //    std::map<int, TcpConnection*> mTcpConnections;
};

#endif //TCPSERVER_H

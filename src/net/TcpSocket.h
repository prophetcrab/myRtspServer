//
// Created by crab on 2024/11/8.
//

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <string>
#include <cstdint>

#include "InetAddress.h"

class  TcpSocket
{
public:
    explicit TcpSocket(int sockfd) :
        mSockfd(sockfd) { }

    ~TcpSocket();

    int fd() const { return mSockfd; }
    bool bind(Ipv4Address& addr);
    bool listen(int backlog);
    int accept();
    void setReuseAddr(int on);

private:
    int mSockfd;
};


#endif //TCPSOCKET_H

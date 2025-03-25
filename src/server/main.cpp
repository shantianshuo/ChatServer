#include "chatserver.hpp"
#include "chatservice.hpp" //用到ChatService作用域，
#include<iostream>
#include <signal.h>
using namespace std;
//服务器ctrl + c 强制退出后，重置user表中state的状态信息
void reserHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}
int main()
{
    signal(SIGINT,reserHandler);
    EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"ChatServer");
    server.start();
    loop.loop();
    return 0;
}
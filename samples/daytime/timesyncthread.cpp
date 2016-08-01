#include <netinet/in.h>    // for sockaddr_in
#include <sys/socket.h>    // for socket
#include <arpa/inet.h>

#include <iostream>
#include <fstream>

#include <timesyncthread.h>
#include <l_nut_log.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <l_nut_log.h>

namespace l_nut_thread {

#define BUFFER_SIZE 1024
    // static char INTERNET_TIME_SERVER_IP[64] = "66.219.116.140";
    static char INTERNET_TIME_SERVER_IP[64] = "129.6.15.29";
    static int INTERNET_TIME_SERVER_PORT = 13;

    timesyncthread::timesyncthread()
        : m_socket(0)
    {
        l_nut_log::print("timesyncthread::constructor");
    }

    timesyncthread::~timesyncthread()
    {
        l_nut_log::print("timesyncthread::destructor");
        if (0 != m_socket) {
            close(m_socket);
            m_socket = 0;
        }
    }

    void timesyncthread::run()
    {
        l_nut_log::print("timesyncthread run.");
        while (1) {
            l_nut_log::print("timesyncthread run to sleep.");
            sleep(10);
            l_nut_log::print("timesyncthread run awaked.");
            syncFromInternet(m_socket);
        }
    }

    void timesyncthread::parse(SYSTEMTIME* sys_time, char* buff)
    {
        if (NULL == sys_time || NULL == buff) {
            return;
        }

        char str[3];
        str[2] = '\0';

        str[0] = buff[7];
        str[1] = buff[8];
        sys_time->wYear = atoi(str) + 2000;

        str[0] = buff[10];
        str[1] = buff[11];
        sys_time->wMonth = atoi(str);

        str[0] = buff[13];
        str[1] = buff[14];
        sys_time->wDay = atoi(str);

        str[0] = buff[16];
        str[1] = buff[17];
        sys_time->wHour = atoi(str);

        str[0] = buff[19];
        str[1] = buff[20];
        sys_time->wMinute = atoi(str);

        str[0] = buff[22];
        str[1] = buff[23];
        sys_time->wSecond = atoi(str);
    }

    void timesyncthread::syncFromInternet(int& client_socket)
    {
        l_nut_log::print("Internet Time Server IP=[%s], Port=[%d]", INTERNET_TIME_SERVER_IP, INTERNET_TIME_SERVER_PORT);

        //设置一个socket地址结构client_addr,代表客户机internet地址, 端口
        struct sockaddr_in client_addr;
        bzero(&client_addr,sizeof(client_addr)); //把一段内存区的内容全部设置为0
        client_addr.sin_family = AF_INET;    //internet协议族
        client_addr.sin_addr.s_addr = htons(INADDR_ANY);//INADDR_ANY表示自动获取本机地址
        client_addr.sin_port = htons(0);    //0表示让系统自动分配一个空闲端口

        l_nut_log::print("Create Socket ...\n");
        //创建用于internet的流协议(TCP)socket,用client_socket代表客户机socket
        client_socket = socket(AF_INET,SOCK_STREAM,0);
        if( client_socket < 0) {
            l_nut_log::print("Create Socket Failed!\n");
            return ;
        }

        l_nut_log::print("Client Bind Port ...\n");
        //把客户机的socket和客户机的socket地址结构联系起来
        if( bind(client_socket,(struct sockaddr*)&client_addr,sizeof(client_addr))) {
            l_nut_log::print("Client Bind Port Failed!\n");
            return ;
        }

        //设置一个socket地址结构server_addr,代表服务器的internet地址, 端口
        struct sockaddr_in server_addr;
        bzero(&server_addr,sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        if(inet_aton(INTERNET_TIME_SERVER_IP,&server_addr.sin_addr) == 0) { //服务器的IP地址
            l_nut_log::print("Server IP Address Error!\n");
            return ;
        }

        l_nut_log::print("Connect ...\n");
        server_addr.sin_port = htons(INTERNET_TIME_SERVER_PORT);
        socklen_t server_addr_length = sizeof(server_addr);
        //向服务器发起连接,连接成功后client_socket代表了客户机和服务器的一个socket连接
        if(connect(client_socket,(struct sockaddr*)&server_addr, server_addr_length) < 0) {
            l_nut_log::print("Can Not Connect To Server!\n");
            return ;
        }

        int length = 0;
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);

        l_nut_log::print("Receive ...\n");
        length = recv(client_socket,buffer,BUFFER_SIZE,0);
        if (length < 0) {
            l_nut_log::print("Client Recieve Data Failed!\n");
            return ;
        }

        close(client_socket);
        client_socket = 0;

        SYSTEMTIME sys_time;
        memset(&sys_time,0,sizeof(SYSTEMTIME));
        parse(&sys_time, buffer);

        l_nut_log::print("timesyncthread Receive time : %s",buffer);
        l_nut_log::print("timesyncthread Receive time wYear: %d",sys_time.wYear);
        l_nut_log::print("timesyncthread Receive time wMonth: %d",sys_time.wMonth);
        l_nut_log::print("timesyncthread Receive time wDay: %d",sys_time.wDay);
        l_nut_log::print("timesyncthread Receive time wHour: %d",sys_time.wHour);
        l_nut_log::print("timesyncthread Receive time wMinute: %d",sys_time.wMinute);
        l_nut_log::print("timesyncthread Receive time wSecond: %d",sys_time.wSecond);
        return ;
    }

}

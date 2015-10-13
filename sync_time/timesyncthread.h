// Copyright (c) 2015 leedefu. All rights reserved.

#ifndef TIMESYNCTHREAD_H
#define TIMESYNCTHREAD_H

#include <pthread.h>
#include <thread/l_nut_thread.h>

namespace l_nut_thread {

    /*redefinition of Linux                                                        */
    typedef struct _SYSTEMTIME {
        unsigned short wYear;
        unsigned short wMonth;
        unsigned short wDayOfWeek;
        unsigned short wDay;
        unsigned short wHour;
        unsigned short wMinute;
        unsigned short wSecond;
        unsigned short wMilliseconds;
    } SYSTEMTIME, *PSYSTEMTIME;

class timesyncthread : public l_thread {

public:
    timesyncthread();
    virtual ~timesyncthread();

public:
    virtual void run();
    void transferTime(SYSTEMTIME* sys_time, char* buff);
    void doInternetTime(int& client_socket);

private:
    int m_socket;

}; // end of class timesyncthread

} // end of namespace

#endif // TIMESYNCTHREAD_H
/* EOF */

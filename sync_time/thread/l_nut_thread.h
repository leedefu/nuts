// Copyright (c) 2015 leedefu. All rights reserved.

#ifndef L_NUT_THREAD_H
#define L_NUT_THREAD_H

#include <pthread.h>

namespace l_nut_thread {

class l_thread {

public:
    l_thread();
    virtual ~l_thread();

public:
    void start_thread(const char* thread_name = "unknown thread name");
    bool stop_thread();

public:
    virtual void run();

protected:
    static void* thread_routine(void* args);

private:

    pthread_t           m_tid;
    pthread_attr_t      m_attr;
    pthread_mutex_t     m_mutex;
    pthread_condattr_t  m_condattr;
    pthread_cond_t      m_cond;

}; // end of class l_thread

} // end of namespace

#endif // L_NUT_THREAD_H
/* EOF */

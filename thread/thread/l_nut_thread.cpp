#include <thread/l_nut_thread.h>
#include <l_nut_log.h>
#include <string.h>

#include <stdio.h>

namespace l_nut_thread {

l_thread::l_thread()
{
    l_nut_log::print("l_thread::constructor");

    int ret = pthread_attr_init(&m_attr);
    if (0 != ret) {
        l_nut_log::print("m_attr init failed %d [%s].", ret, strerror(ret));
        // ? l_nut_log::print("m_attr init failed %d [%s].", ret, strerror(errno));
    }

    ret = pthread_attr_setstacksize(&m_attr, 64*1024);
    if (0 != ret) {
        l_nut_log::print("m_attr stacksize init failed %d [%s].", ret, strerror(ret));
    }

    ret = pthread_mutex_init(&m_mutex, NULL);
    if (0 != ret) {
        l_nut_log::print("m_mutex init failed %d [%s].", ret, strerror(ret));
    }

    pthread_condattr_init(&m_condattr);
    int err = pthread_condattr_setclock(&m_condattr, CLOCK_MONOTONIC);
    if (err) {
        l_nut_log::print("Error setting clock: %d\n", err);
    }

    ret = pthread_cond_init(&m_cond, &m_condattr);
    if (0 != ret) {
        l_nut_log::print("Thread m_cond init failed %d [%s].", ret, strerror(ret));
    }
}

l_thread::~l_thread()
{
    l_nut_log::print("l_thread::destructor");

    pthread_attr_destroy(&m_attr);
    pthread_cond_destroy(&m_cond);
    pthread_condattr_destroy(&m_condattr);
}

void l_thread::start_thread(const char* thread_name)
{
    l_nut_log::print("l_thread::start_thread(%s)", thread_name);
    
    int ret = pthread_create(&m_tid, &m_attr, thread_routine, this);
    if (0 == ret) {
        l_nut_log::print("Start thread.");
    }
}

bool l_thread::stop_thread()
{
    l_nut_log::print("l_thread::stop_thread");
    if (!m_tid) {
        return true;
    }

    int ret = pthread_cancel(m_tid);
    if (0 == ret) {
        return true;
        // return join();
    }
    else {
        l_nut_log::print("Stop thread failed %d [%s].", ret, strerror(ret));
        return false;
    }
}

void l_thread::run()
{
    l_nut_log::print("new thread run......");
    while (1) {
        l_nut_log::print("new thread will sleep in run function.");
        sleep(10);
        l_nut_log::print("new thread awaked in run function.");
    }
}

void* l_thread::thread_routine(void* args)
{
    l_nut_log::print("thread_routine.");
    static_cast<l_thread*>(args)->run();
}
 
}

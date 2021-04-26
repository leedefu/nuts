#include <stdio.h>
#include <thread>
#include <mutex>
#include <chrono>

#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

std::recursive_mutex g_mutex;

void l_printf(const char* format, ...)
{
    // printf("[l_nut_thread pid=%d, tid=%d]:", getpid(), syscall(SYS_gettid));
    printf("[pid=%d, tid=%ld] ", getpid(), syscall(__NR_gettid));
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void do_something()
{
    l_printf("do_something ......\n");
    std::this_thread::sleep_for(std::chrono::seconds(5));
    l_printf("do_something end\n");
}

void common_func()
{
    l_printf("common_func\n");

    // deadlock in thread_1 !!!
    std::unique_lock<std::recursive_mutex> lock(g_mutex);

    l_printf("common_func end\n");
}

void thread_1_func()
{
    l_printf("thread_1_func\n");
    std::unique_lock<std::recursive_mutex> lock(g_mutex);

    // call common_func
    common_func();


    do_something();


    l_printf("thread_1_func end\n");
}

void thread_2_func()
{
    l_printf("thread_2_func\n");
    std::unique_lock<std::recursive_mutex> lock(g_mutex);

    // call common_func
    // common_func();

    do_something();

    l_printf("thread_2_func end\n");
}

/////////////////////////////////////////////
int main(int argc, char* argv[])
{
    l_printf("Test for mutex\n");

    std::thread thread1(thread_1_func);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread thread2(thread_2_func);

    thread1.join();
    thread2.join();

    return 0;
}


#include <stdio.h>

#include <vector>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>


bool bQuit = false;

std::mutex g_mutex;
std::condition_variable g_condition_variable;
std::vector<int32_t> g_vector;

void l_printf(const char* format, ...)
{
    printf("[pid=%d, tid=%ld] ", getpid(), syscall(__NR_gettid));
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void thread_1_func()
{
    l_printf("thread_1_func\n");

    while(!bQuit) {
        std::unique_lock<std::mutex> lock(g_mutex);

        for (auto item : g_vector) {
            l_printf("handle item:[%d]\n", item);
        }
        g_vector.resize(0);

        l_printf("condition wait\n");
        // when wait, automatic unlock
        g_condition_variable.wait(lock, []{return (g_vector.size() != 0);});
        l_printf("condition wait end\n");
    }

    l_printf("thread_1_func end\n");
}

void thread_2_func()
{
    l_printf("thread_2_func\n");

    while(!bQuit) {

        std::unique_lock<std::mutex> lock(g_mutex);

        // push data into critical section
        static int32_t data = 0;
        g_vector.push_back(data++);
        g_vector.push_back(data++);
        g_vector.push_back(data++);

        lock.unlock();

        l_printf("condition notify_one\n");
        g_condition_variable.notify_one();
        l_printf("condition notify_one end\n");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    l_printf("thread_2_func end\n");
}

void thread_3_func()
{
    l_printf("thread_3_func\n");

    while(!bQuit) {
        std::unique_lock<std::mutex> lock(g_mutex);

        l_printf("condition wait\n");
        // when wait, automatic unlock
        g_condition_variable.wait_for(lock, std::chrono::seconds(10), []{return (g_vector.size() != 0);});
        // g_condition_variable.wait(lock, []{return (g_vector.size() != 0);});
        l_printf("condition wait end\n");
    }

    l_printf("thread_1_func end\n");
}
/////////////////////////////////////////////
int main(int argc, char* argv[])
{
    l_printf("Test for condition_variable\n");


    std::thread thread4(thread_3_func);

        std::this_thread::sleep_for(std::chrono::seconds(3));
            g_vector.resize(1);
        l_printf("condition notify_one\n");
        g_condition_variable.notify_one();
        l_printf("condition notify_one end\n");

    thread4.join();
    return 0;


    std::thread thread2(thread_2_func);
    std::thread thread3(thread_2_func);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread thread1(thread_1_func);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}

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

std::recursive_mutex g_mutex;
std::condition_variable_any g_condition_variable;
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
    l_printf("thread_func handle vector\n");

    while(!bQuit) {
        std::unique_lock<std::recursive_mutex> lock(g_mutex);

        l_printf("handle item size:[%d] size%3:[%d]\n", g_vector.size(), g_vector.size()%3);
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
    l_printf("thread_func push vector\n");

    while(!bQuit) {

        std::unique_lock<std::recursive_mutex> lock(g_mutex);

        // push data into critical section
        l_printf("thread_func push vector\n");
        static int32_t data = 0;
        g_vector.push_back(data++);
        g_vector.push_back(data++);
        g_vector.push_back(data++);

        lock.unlock();

        // std::this_thread::sleep_for(std::chrono::seconds(2));

        l_printf("condition notify_one\n");
        g_condition_variable.notify_one();
        l_printf("condition notify_one end\n");

        // std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    l_printf("thread_2_func end\n");
}

/////////////////////////////////////////////
int main(int argc, char* argv[])
{
    l_printf("Test for condition_variable_any\n");

    std::thread thread2(thread_2_func);
    std::thread thread3(thread_2_func);

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread thread1(thread_1_func);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}


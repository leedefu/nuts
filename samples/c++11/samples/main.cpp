#include <stdio.h>
#include <thread>
#include "common.h" 

void thread_1()
{
    printf("thread_1\n");
    printf("1 + 1=%d\n", add_1(1, 1));
}

int main(int argc, char* argv[])
{
    /* [auto] feature                        */
    int a = 1;
    auto b = a;
    printf("a = %d, b = %d\n", a, b);
    /*---------------------------------------*/

    /* thread */
    std::thread th(thread_1);
    th.join();

    printf("main thread\n");

    return 0;
}

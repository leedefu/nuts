#include <stdio.h>
#include "thread/l_nut_thread.h"
#include <l_nut_log.h>

using namespace l_nut_thread;

int main(int argc, char* argv[])
{
    l_nut_log::print("thread sample.");

    l_thread thread_1;
    thread_1.start_thread();

    l_nut_log::print("enter loop");
    while (1) {
        l_nut_log::print("main to sleep.");
        sleep(1);
        l_nut_log::print("run awaked.");
    }

    return 0;
}

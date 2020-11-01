#ifndef L_NUT_LOG_H
#define L_NUT_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace l_nut_thread {

class l_nut_log {

public:
    static void print(const char* format, ...)
    {
        // TODO: research below:
        // printf("[l_nut_thread pid=%d, tid=%d]:", getpid(), syscall(SYS_gettid));
        printf("[l_nut_thread pid=%d, tid=%ld]: ", getpid(), syscall(__NR_gettid));
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }
};

}

#endif // L_NUT_LOG_H

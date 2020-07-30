#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <sys/syscall.h>
#include <stdarg.h>
#include <string.h>

// define log type
typedef enum NUTS_LOGTYPE
{
    NUTS_LOG_DEBUG = 1,    // Debug log
    NUTS_LOG_INFO,         // Normal log
    NUTS_LOG_WARNING,      // warning log
    NUTS_LOG_ERROR         // Error log
} NUTS_LOGTYPE;

// #define NUTS_LOGTYPE_DEFAULT NUTS_LOG_INFO
#define NUTS_LOGTYPE_DEFAULT NUTS_LOG_DEBUG

#define NUTS_LOG_SINGLE_LOG_SIZE 1024

void nuts_time_get_timespec(struct timespec* time,  uint32_t msec)
{
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);

    time->tv_sec = now.tv_sec + msec/1000;
    time->tv_nsec = now.tv_nsec + (msec % 1000) * 1000000;

    // bigger than one second
    if (time->tv_nsec >= 1000000000) {
        time->tv_sec++;
        time->tv_nsec -= 1000000000;
    }
}

void nuts_time_set_timespec(struct timespec* time,  uint32_t msec)
{
    time->tv_sec += msec / 1000;
    time->tv_nsec += (msec % 1000) * 1000000;

    // bigger than one second
    if (time->tv_nsec >= 1000000000) {
        time->tv_sec++;
        time->tv_nsec -= 1000000000;
    }
}

long nuts_time_sub_timespec(struct timespec* time1, struct timespec* time2)
{
    if ((NULL == time1) || (NULL == time2)) {
        return 0;
    }

    long ms = time1->tv_sec * 1000 + time1->tv_nsec / 1000000
        - (time2->tv_sec * 1000 + time2->tv_nsec / 1000000);

    return ms;
}

int64_t nuts_time_get_tick_count()
{
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    return time.tv_sec*1000 + time.tv_nsec/1000000;
}

int64_t nuts_time_get_thread_time()
{
    struct timespec time;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time);
    return time.tv_sec*1000 + time.tv_nsec/1000000;
}

void nuts_output(NUTS_LOGTYPE type, const char *format, ...)
{
    if (type >= NUTS_LOGTYPE_DEFAULT) {
        if (NULL == format) {
            return;
        }

        char buff[NUTS_LOG_SINGLE_LOG_SIZE] = { 0 };

        va_list list;
        va_start(list, format);
        vsnprintf(buff, sizeof(buff), format, list);
        va_end(list);

        if (NUTS_LOG_ERROR == type) {
            fprintf(stderr, "[TC:%" PRId64 " TT:%" PRId64 " PID:%d TID:%ld] ERROR: %s\n", nuts_time_get_tick_count(),
                   nuts_time_get_thread_time(), getpid(), syscall(__NR_gettid), buff);
        }
        else if (NUTS_LOG_WARNING == type) {
            fprintf(stderr, "[TC:%" PRId64 " TT:%" PRId64 " PID:%d TID:%ld] WARNING: %s\n", nuts_time_get_tick_count(),
                   nuts_time_get_thread_time(), getpid(), syscall(__NR_gettid), buff);
        }
        else {
            fprintf(stderr, "[TC:%" PRId64 " TT:%" PRId64 " PID:%d TID:%ld] %s\n", nuts_time_get_tick_count(),
                   nuts_time_get_thread_time(), getpid(), syscall(__NR_gettid), buff);
        }
    }
    else {
        // do not output log
    }
}

typedef int (*glibc_free)(char* ptr);
typedef void* (*glibc_malloc)(size_t n);
typedef void* (*glibc_calloc_type)(size_t, size_t);

#if 0
glibc_calloc_type calloc_fuc = NULL;


void beforemain() __attribute__((constructor));

void beforemain()
{
    nuts_output(NUTS_LOG_INFO, "beforemain\n");
    // glibc_calloc_type calloc_fuc = (glibc_calloc_type)dlsym(RTLD_NEXT, "calloc");
}

void* calloc(size_t n, size_t len)
{
    // glibc_calloc_type calloc_fuc = (glibc_calloc_type)dlsym(RTLD_NEXT, "calloc");
    // void* ret = (void*)calloc_fuc(n, len);
    // nuts_output(NUTS_LOG_INFO, "mycalloc(%p)\n", ret);
    // return ret;
    // return NULL;

    // glibc_malloc malloc_fuc = (glibc_malloc)dlsym(RTLD_NEXT, "malloc");
    // void* ret = (void*)malloc_fuc(1024);
    // nuts_output(NUTS_LOG_INFO, "+++++++ mymalloc(%p)\n", ret);
    // return ret;
    // return NULL;
}

#endif

void free(char* ptr)
{
    glibc_free free_fuc = (glibc_free)dlsym(RTLD_NEXT, "free");
    nuts_output(NUTS_LOG_INFO, "--------- myfree(%p)\n", ptr);
    free_fuc(ptr);
}

void* malloc(size_t n)
{
    glibc_malloc malloc_fuc = (glibc_malloc)dlsym(RTLD_NEXT, "malloc");
    void* ret = (void*)malloc_fuc(n);
    nuts_output(NUTS_LOG_INFO, "+++++++ mymalloc(%p)\n", ret);
    return ret;
}


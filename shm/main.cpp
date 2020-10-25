#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */


#define DF_SHM_NAME "DF_SHM"
#define DF_SHM_SIZE 4096

int main(int argc, char* argv[])
{
    printf("Subject: shm\n");
    if (argc < 2) {
        printf("Usage: %s [OPTION]\n"
               " \t-w write shm\n"
               "\t-r read shm\n",
               argv[0]);

        return -1;
    }

    // create and write shm
    if (strcmp(argv[1], "-w") == 0) {
        printf("create and write shm\n");

        printf("shm_open\n");
        // create/open POSIX shared memory objects
        int fd = shm_open(DF_SHM_NAME, O_RDWR|O_CREAT, 0644);
        if (-1 == fd) {
            printf("shm_open failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        {
        #if 0
            int count = 1000;
            int times = 1;
            while(count-- > 0) {
                printf("shm_open times:%d\n", times);
                fd = shm_open(DF_SHM_NAME, O_RDWR|O_CREAT, 0777);
                times++;
                if (-1 == fd) {
                    printf("shm_open failed errno:%d errmsg:%s\n", errno, strerror(errno));
                    return -1;
                }
            }
        #endif
        }

        printf("ftruncate\n");
        // truncate a file to a specified length
        int ret = ftruncate(fd, DF_SHM_SIZE);
        if (-1 == ret) {
            printf("ftruncate failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        printf("mmap fd:%d\n", fd);
        // map files or devices into memory
        void* addr = mmap(NULL, DF_SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SEEK_SET);
        if (MAP_FAILED == addr) {
            printf("mmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        printf("close fd:%d\n", fd);
        close(fd);
        fd = -1;

        printf("memcpy to write shm (attention: write string data)\n");
        // write share memory
        memcpy(addr, "123", 3);

        printf("munmap\n");
        // unmap files or devices from memory space
        ret = munmap(addr, DF_SHM_SIZE);
        if (-1 == ret) {
            printf("munmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        {
#if 0
            printf("shm_unlink\n");
            // unlink POSIX shared memory objects
            ret = shm_unlink(DF_SHM_NAME);
            if (-1 == ret) {
                printf("munmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
                return -1;
            }
#endif
        }
    }
    else { // read shm
        printf("read shm\n");

        printf("shm_open\n");
        // open POSIX shared memory objects
        int fd = shm_open(DF_SHM_NAME, O_RDONLY, 0644);
        if (-1 == fd) {
            printf("shm_open failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        printf("mmap fd:%d\n", fd);
        // map files or devices into memory
        void* addr = mmap(NULL, DF_SHM_SIZE, PROT_READ, MAP_SHARED, fd, SEEK_SET); // attention: MUST be RROT_READ
        if (MAP_FAILED == addr) {
            printf("mmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

        printf("close fd:%d\n", fd);
        close(fd);
        fd = -1;

        char* buf = new char[DF_SHM_SIZE];
        if (nullptr == buf) {
            printf("new failed\n");
            return -1;
        }
        memset(buf, 0, DF_SHM_SIZE);

        printf("read from shm\n");
        // read share memory
        memcpy(buf, addr, DF_SHM_SIZE);

        printf("read share memory content string: %s\n", buf);
        delete[] buf;
        buf = nullptr;

        printf("munmap\n");
        // unmap files or devices from memory space
        int ret = munmap(addr, DF_SHM_SIZE);
        if (-1 == ret) {
            printf("munmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }

#if 1
        printf("shm_unlink\n");
        // unlink POSIX shared memory objects
        ret = shm_unlink(DF_SHM_NAME);
        if (-1 == ret) {
            printf("munmap failed errno:%d errmsg:%s\n", errno, strerror(errno));
            return -1;
        }
#endif
    }


    printf("sleep \n");
    int count = 10;
    while (count-- > 0) {
        sleep(1);
    }

    printf("normal exit\n");
    return 0;
}

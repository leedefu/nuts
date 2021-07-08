#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


static int idata = 111;        // allocated in data segment
int main(int argc, char* argv[])
{
    int istack = 222;        // allocated in stack segment
    pid_t pid = fork();
    switch (pid) {
    case -1:
        printf("PID=%ld fork error\n", (long)getpid());
        break;
    case 0:
        printf("PID=%ld fork ok, child process\n", (long)getpid());
        idata *= 3;
        istack *= 3;
        printf("PID=%ld child process sleeping 5 seconds....\n", (long)getpid());
        sleep(5);
        printf("PID=%ld child process waked up\n", (long)getpid());
        execve("./tst_sayhello", NULL, NULL);
        break;
    default:
        printf("PID=%ld parent process \n", (long)getpid());
        int status = -1;
        printf("PID=%ld parent process waiting......\n", (long)getpid());
        pid_t id = wait(&status);
        printf("PID=%ld the process ID of the terminated child is %ld \n", (long)getpid(), id);
        // printf("PID=%ld before sleeping\n", (long)getpid());
        // sleep(3); // give child a chance to execute
        // printf("PID=%ld waked up \n", (long)getpid());
        break;
    }
    printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(), (pid == 0)?"(child)":"(parent)", idata, istack);
    return 0;
}

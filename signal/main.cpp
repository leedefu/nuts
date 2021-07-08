#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static void signal_handler(int sig)
{
    printf("signal_handler start\n");
    printf("signal code value: %d\n", sig);
    switch (sig) {
        case SIGINT:
            printf("signal: SIGINT (CTRL+C)\n");
            break;
        default:
            break;
    }
    printf("signal_handler end\n");
    _exit(0); // exit() function is UNSAFE, flush stdio before calling _exit()
}

static void help()
{
    printf("usage:\n");
    printf("     -h/--help show help message\n");
    printf("     signal string\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        help();
        return 0;
    }

    int signum = -1; 
    if (strcmp("SIGINT", argv[1]) == 0) {
        signum = SIGINT;
    }
    if (strcmp("SIGABRT", argv[1]) == 0) {
        // signum = SIGABRT;
        // 1. When a process calls the abort() function, it is sent SIGABRT by SYSTEM automotively.
        // And BY DEFAULT, SIGABRT terminates the process with a core dump.
        //
        // 2.When SIGABRT is sent manually to a process (eg. kill -s SIGABRT <pid>),  
        // the process will be terminiated with a core dump.
        // if (SIG_ERR == signal(SIGABRT, signal_handler)) {
        //     printf("signal error\n");
        //     exit(-1);
        // }
        abort(); // default signal handler will terminate the process and produce a core dump for debugging.
    }
    else {
    }

    if (-1 == signum) {
        printf("inputed signal error\n");
        return 0;
    }

    if (SIG_ERR == signal(signum, signal_handler)) {
        printf("signal error\n");
        exit(-1);
    }

    for (int i = 0; ; ++i) {
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}

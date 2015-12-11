#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static void signal_handler(int sig)
{
    printf("starting signal_handler\n");
    printf("you just have inputed CTRL+C, exit process......\n");
    exit(0);
}

int main(int argc, char* argv[])
{
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        printf("signal error");
        exit(-1);
    }

    for (int i = 0; ; ++i) {
        printf("%d\n", i);
        sleep(3);
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    printf("PID=%ld Hello Everyone\n", (long)getpid());
    return 0;
}

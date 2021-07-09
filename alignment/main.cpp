#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

int main(int argc, char* argv[])
{


    printf("Subject: align\n");
    // _Alignof

    struct S {
        char a;
        int32_t b;
    }__attribute__((aligned(4)));

    struct S s;
    printf("sizeof(s)       =[%d]\n", sizeof(s));
    printf("&s              =[%p]\n", &s);
    printf("(uint64_t)(&s)  =[%u]\n", (uint64_t)(&s));
    printf("s address % 4   =[%d]\n", ((int)(&s))%4);
    printf("s address % 8   =[%d]\n\n", ((int)(&s))%8);

    ////////////////////////////////////////////////////////

    struct S1 {
        char a;
        int32_t b;
    }__attribute__((aligned(8)));

    struct S1 s1;
    printf("sizeof(s1)      =[%d]\n", sizeof(s1));
    printf("&s1             =[%p]\n", &s1);
    printf("(uint64_t)(&s1) =[%u]\n", (uint64_t)(&s1));
    printf("s1 address % 4  =[%d]\n", ((int)(&s1))%4);
    printf("s1 address % 8  =[%d]\n", ((int)(&s1))%8);

    return 0;
}

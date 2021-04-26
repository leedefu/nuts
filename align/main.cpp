#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */


class Test {
public:
    Test()
    {
        printf("Test constructor\n");
    }

    ~Test()
    {
        printf("Test deconstructor\n");
    }
};


int main(int argc, char* argv[])
{
#if 0
    printf("Subject: align\n");

    {
        struct S {
            char a;
            int32_t b;
        };

        S s;
        printf("sizeof(s)=%d\n", sizeof(s));
        printf("s addr 4 = %d\n", ((int)(&s))%4)
    }

    {
        struct S1 {
            char a;
            int32_t b;
        }__attribute__((aligned(8)));

        S1 s1;
        printf("sizeof(s1)=%d\n", sizeof(s1));
        printf("s1 addr 4 = %d\n", ((int)(&s1))%8)
    }
#endif


    Test t;

    while(1) {
        sleep(1);
    }


    return 0;
}

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("c++11 lambda samples\n");

    int a = 1;
    int b = 2;

    auto func = [=, &b](int c)->int {return (b = b + (a + c));};

    printf("a=%d, b=%d\n", a, b);

    printf("call func(3) result=%d\n", func(3));
    printf("a=%d, b=%d\n", a, b);

    printf("call func(4) result=%d\n", func(4));
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

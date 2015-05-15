#include <stdio.h>

/*------------------------------------------*/
class a1
{
    // virtual void func();
};

class b1 : public virtual a1
{
    // virtual void func();
};
/*------------------------------------------*/

int main(int argc, char* argv[])
{
    printf("sizeof(a1) = %d \n", sizeof(a1));
    // result 1


    printf("sizeof(b1) = %d \n", sizeof(b1));
    // result 8

    return 0;
}

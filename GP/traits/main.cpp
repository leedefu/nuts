#include <stdio.h>

template <typename T>
struct TraitsHelper {
    static const bool isPointer = false;
};

template <typename T>
struct TraitsHelper<T*> {
    static const bool isPointer = true;
};

int main(int argc, char* argv[])
{
    printf("test traits\n");
    printf("TraitsHelper<int>::isPointer:%d\n", TraitsHelper<int>::isPointer);
    printf("TraitsHelper<int*>::isPointer:%d\n", TraitsHelper<int*>::isPointer);

    return 0;
}

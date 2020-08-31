#include <unistd.h>
#include <stdio.h>
#include <string>
#include <memory>

class A {
public:
    A ():i(256) {}

    // Class B is friend class of class A defaultly
    class B {
        public:
            void func();
    };

private:
    int i;
};

void A::B::func() {
    A a;
    printf("a.i:%d\n", a.i);
}

int main(int argc, char* argv[])
{
    A::B b;
    b.func();

    return 0;
}

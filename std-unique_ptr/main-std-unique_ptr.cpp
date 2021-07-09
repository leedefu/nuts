#include <unistd.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>

class Test {
public:
    Test() 
    {
        printf("construct\n");
    }

    ~Test() 
    {
        printf("deconstruct\n");
    }

    Test(const Test& a) 
    {
        printf("copy construct\n");
    }

    Test& operator=(const Test& a) 
    {
        printf("assign \n");
    }

    Test(Test&& a) 
    {
        printf("rvalue copy construct\n");
    }

    Test& operator=(Test&& a) 
    {
        printf("rvalue assign \n");
        return *this;
    }

};

void func_2(std::unique_ptr<Test> param)
{

}

int main(int argc, char* argv[])
{
    printf("Test for unique_ptr\n");

    std::unique_ptr<Test> ptr = std::make_unique<Test>();

    // must be std::move
    func_2(std::move(ptr));

    // std::unique_ptr<Test> ptr{new Test()};
    std::unique_ptr<Test> ptr_1 = std::move(ptr);


    int count = 10;
    while(count-- > 0) {
        sleep(1);
    }

    return 0;
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <stdarg.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

class Base {
public:
    Base(int32_t i) : m(i) { std::cout<< "Base::Base\n"; }
    virtual ~Base() { std::cout<< "Base::~Base\n"; }
public:
    int32_t m;
};

class Derived: public Base {
public:
    Derived(int32_t i) : Base(i) { std::cout<< "Derived::Derived\n"; }
    virtual ~Derived() { std::cout<< "Derived::~Derived\n"; }
};

int main(int argc, char* argv[])
{
    printf("Test for shared_ptr\n");

    {
        std::vector<std::shared_ptr<Base>> v1;
        {
            std::vector<std::shared_ptr<Base>> v2;
            v2.push_back(std::make_shared<Derived>(0));
            v2.push_back(std::make_shared<Derived>(1));
            
            printf("v2 size:%lu\n", v2.size());
            for (auto item : v2) {
                std::cout<<"v2 item:"<<item->m<<std::endl;
            }

            v1 = v2;
            v2.clear();
            printf("after v2 clear, v2 size:%lu\n", v2.size());
        }

        printf("v1 size:%lu\n", v1.size());
        for (auto item : v1) {
            std::cout<<"v1 item:"<<item->m<<std::endl;
        }

        printf("v2 scope exit\n");
    }

    printf("v1 scope exit\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}


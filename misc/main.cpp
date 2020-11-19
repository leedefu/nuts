#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <memory>
#include <iostream>

void func(const char* data, int size)
{
    void* buf = malloc(size);
    memcpy(buf, data, size);
}

int main(int argc, char* argv[])
{
    {
        std::string data("Hello Server.");
        func(data.data(), data.size());
    }

    // std::string str1 = "abc";
    // std::string str2 = "abcd";
    // std::cout<< "str1:"<<str1<<std::endl;
    // std::cout<< "str2:"<<str2<<std::endl;
    // std::cout<< "str1.compare(str2)= " << str1.compare(str2) <<std::endl;
    // std::cout<< "str2.compare(str1)= " << str2.compare(str1) <<std::endl;
    void* p = malloc(100);
    return 0;
}

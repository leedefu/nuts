#include <stdio.h>
#include <iostream>
#include <typeinfo>

class ClassA {
public:
    ClassA() {
        std::cout<< "constructor"<<std::endl;
    }
    ~ClassA() {
        std::cout<< "destructor"<<std::endl;
    }

    ClassA(const ClassA& a) {
        std::cout<< "copy constructor"<<std::endl;
    }

    ClassA& operator=(const ClassA& a) {
        std::cout<< "assign constructor"<<std::endl;
        return *this;
    }

    ClassA(ClassA&& a) {
        std::cout<< "rvalue copy constructor"<<std::endl;
    }

    ClassA& operator=(ClassA&& a) {
        std::cout<< "rvalue assign constructor"<<std::endl;
        return *this;
    }

};


static void normal_func(ClassA& a)
{
    std::cout<<"normal_func lvalue parameter"<<std::endl;
}

static void normal_func(ClassA&& a)
{
    std::cout<<"normal_func rvalue parameter"<<std::endl;
}

template<typename T>
static void template_func(T&& a)
{
    std::cout<<"template_func"<<std::endl;
    std::cout<<"typeid(T).name="<< typeid(T).name() <<std::endl;
}

void tst_lrvalue()
{
    std::cout<<">>> Test lvalue and rvalue >>>>>>"<<std::endl;

    ClassA a;

    // ClassA a1(std::move(a));

    // normal_func(a); // error: cannot bind ‘ClassA’ lvalue to ‘ClassA&&
    // normal_func(std::move(a));

    template_func(a);
    template_func(std::move(a));

    std::cout<<"<<< Test lvalue and rvalue <<<<<<"<<std::endl;
}

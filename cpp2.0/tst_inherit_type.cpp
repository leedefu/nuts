#include <cstdio>
#include <cinttypes>
#include <string>

class B 
{
public:
    using SelfType = double;
    double func1()
    {
        printf("B func1 \n");
        return 1.0;
    }

};

class C
{
public:
    using SelfType = std::string;
    std::string func1()
    {
        printf("C func1 \n");
        return "1.0";
    }

};

class A : public B, public C
{
public:
    using SelfType = std::int64_t;
    std::string func1()
    {
        printf("A func1 \n");
        return "1.0";
    }

};

class Base {
public:
#if 0
    virtual double getInt() 
    {
        printf("Base get Int\n");
        return 1.0;
    }
#endif
};

class Node {
public:
    virtual int getInt() 
    {
        printf("Node get Int\n");
        return 0;
    }
};

class Value : public Node , public Base {
public:
    virtual std::string get() 
    {
        printf("Value get \n");
        return "123";
    }
};

class Object : public Value {
public:
    std::string get() 
    {
        printf("Object get \n");
        return "123";
    }

    int getInt()
    {
        printf("Object getInt \n");
    }
};

void tst_inherit_type()
{
    printf("test inherit_type\n");

    Value* n = new Object();
    n->get();
    // n->getInt();
    // Value v;
    // v.get();
#if 0
    A a;
    A::SelfType t = 1;
    a.func1();
#endif

}

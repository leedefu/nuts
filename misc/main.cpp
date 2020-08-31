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


void func_1(const std::string& para = "default string")
{
    printf("para:%s\n", para.c_str());
}

void func_2(const std::unique_ptr<std::string>& para = {})
{
    printf("func_2\n");
}

std::unique_ptr<std::string> getMsg()
{
    return std::unique_ptr<std::string>(new std::string("1234"));
}

int main(int argc, char* argv[])
{

#if 0
    int a = 0;
    for (int i = 0; i < 5; ++i) {
        sleep(3);
        printf("i=%d\n", i);
        printf("a=%d\n", a);
        if (i == 0) {
            continue;
        }
        ++a;
    }
#endif

    int count = 5;
    int key = 5;
    do {
        printf("count=%d\n", count);
        printf("key=%d\n", key);
        sleep(3);
        if (count < 3) {
            continue;
        }
        count--;
    
    } while (count > 0 && (--key) > 0);

return 0;
    // std::unique_ptr<std::string> strMsg1(new std::string("1234"));
    std::unique_ptr<std::string> strMsg1 = getMsg();
    func_2();
    func_2(strMsg1);

return 0;
    std::string strMessage("message1");
    func_1();

return 0;
    A::B b;
    b.func();

    return 0;
}

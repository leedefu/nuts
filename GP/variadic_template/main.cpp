#include <stdio.h>
#include <iostream>
#include <initializer_list>

template <typename T>
T GetAs()
{
    printf("GetAs\n");
    T t;
    return t;
}

//////////////////////////////////////////////////////////////////////
/* variadic template function parameter unpack 
   method1: recursive call
*/
#if 0
// case1:
void _printX()
{
    std::cout<<"void _printX()"<<std::endl;
}
#endif

// case2:
template <typename T>
void _printX(T first)
{
    std::cout<<"void _printX(T first)"<<std::endl;
    std::cout<<first<<std::endl;
}

template <typename T, typename... Args>
void _printX(T first, Args... args)
{
    std::cout<<"void _printX(T first, Args... args)"<<std::endl;
    // handle [first]
    std::cout<<"first: "<<first<<std::endl;
    std::cout<<"args size: "<<sizeof...(args)<<std::endl;

    // handler [args]
    // why wrong: _printX<T>(args...);
    _printX(args...);
}


template<typename T>
T sum(T t)
{
    return t;
}

template<typename T, typename ... Types>
T sum (T first, Types ... rest)
{
    // why ok: return first + sum<T>(rest...);
    return first + sum(rest...);
}
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/* variadic template function parameter unpack 
   method2: comma expression 
*/
template <class T>
void printarg(T t)
{
   std::cout << t << std::endl;
}

template <class ...Args>
void expand(Args... args)
{
    std::cout<<"sizeof...(args):"<<sizeof...(args)<<std::endl;
#if 0
    // int arr[] = {0, (printarg(args), 0)...};
    // ATTENTION
    int arr[] = {(printarg(args), 0)...};
    std::cout<<"sizeof(arr):"<<sizeof(arr)<<std::endl;
    std::cout<<"size of arr:"<<sizeof(arr)/sizeof(int)<<std::endl;
#endif
    std::initializer_list<int>{(printarg(args), 0)...};
}
//////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{
    std::cout<<"Test for template"<<std::endl;
    std::cout<<"+++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    _printX(1, 2.0, "a string");

    // int i = GetAs<int>();

    std::cout<<"sum: "<<sum(1, 2, 3, 4)<<std::endl; //10

    expand(1,2,3,4);

    return 0;
}

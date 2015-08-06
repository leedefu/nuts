#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <wchar.h>
#include <errno.h>
#include <unistd.h>
#include <utime.h>
#include <sys/types.h>
#include <syscall.h>
#include <stdint.h>
#include <bits/wordsize.h>
#include <string>
#include <iostream>

using namespace std;

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

    int32_t x = 90;
    float f = (float)x / 100;
    printf("f=%f\n", f);
    if (f == 0.900000) {
        printf("f=0.900000\n");
    }
    int32_t y = f * 100;
    printf("y=%d\n", y);
    if (y == 90) {
        printf("y=90\n");
    }



#if 0
    printf("sizeof(a1) = %d \n", sizeof(a1));
    // result 1


    printf("sizeof(b1) = %d \n", sizeof(b1));
    // result 8
    
    // buffer
    unsigned char data[12] = { 0 };

    {
        // write 
        std::string strDir("0f03ed");

        int32_t id = 10;
        int32_t flag = 1;
        int32_t dir = std::stoi(strDir, 0, 16);
        // int32_t dir = ::atoi(strDir.c_str());
        printf("\n------write--------------------\n");
        printf("id=%d, flag=%d, dir=%06x, strDir=%s\n", id, flag, dir, strDir.c_str());
        printf("------write--------------------\n\n");
        
        memcpy(data, &id, sizeof(id));
        memcpy(data + sizeof(id), &flag, sizeof(flag));
        memcpy(data + sizeof(id) + sizeof(flag), &dir, sizeof(dir));
    }

    {
        // read 

        int32_t id = 0;
        int32_t flag = 0;
        int32_t dir = 0;
        
        memcpy(&id, data, sizeof(id));
        memcpy(&flag, data + sizeof(id), sizeof(flag));
        memcpy(&dir, data + sizeof(id) + sizeof(flag), sizeof(dir));

        char strDir[8] = {0};
        snprintf(strDir, 8, "%06x", dir);
        // std::string strDir = std::to_string(dir);

        printf("\n------read--------------------\n");
        printf("id=%d, flag=%d, dir=%06x, strDir=%s\n", id, flag, dir, strDir);
        printf("------read--------------------\n\n");
    }

#endif
    return 0;
}

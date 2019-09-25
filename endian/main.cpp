#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    {
        int a = 0x87654321;
        unsigned char* p = (unsigned char*)&a;
        {
            char str[20] = { 0 };
            sprintf(str,"%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
            printf(str);
            printf("\n");
        }

        {
            char str[20] = { 0 };
            sprintf(str,"0x%x.0x%x.0x%x.0x%x", p[0], p[1], p[2], p[3]);
            printf(str);
            printf("\n");
        }
    }

    // method 1
    /* using union to check endian */
    /***********************************************************/
    union {
        int i;
        char c;
    } u;

#if 0
    u.i = 0x00000001;
    if (u.c == 0x01) {
        printf("little endian\n");
    }
    else {
        printf("big endian\n");
    }
#endif

    u.i = 0x00000023;
    if (u.c == 0x23) {
        printf("little endian\n");
    }
    else {
        printf("big endian\n");
    }

    printf("char value 0x%0x, char character %c\n", u.c, u.c);
    /***********************************************************/

    // method 2
    /***********************************************************/
    static union { char c[4]; unsigned int myint; } endian_test = { {'l', '?', '?', 'b'} };
#define ENDIANNESS ((char)endian_test.myint)

    printf("ENDIANNESS is %c\n", ENDIANNESS);
    if (ENDIANNESS == 'l') {
        printf("little endian\n");
    }
    else {
        printf("big endian\n");
    }
    /***********************************************************/

    // method 3 (different with method 2, same as method 1)
    /***********************************************************/
    /*
        low address -> high address
        endiantest 1:
            |xx|xx|xx|xx|

            |xx|xx|xx|xx|
            ^
            |
        reinterpret_cast<char *>(&endiantest)

            |xx|
            ^
            |
        *reinterpret_cast<char *>(&endiantest)
            
        
    */

    int endiantest = 1;
    // If this fails, see FLATBUFFERS_LITTLEENDIAN above.
    if (*reinterpret_cast<char *>(&endiantest) == 1) {
        printf("method 3 little endian\n");
    }
    else {
        printf("method 3 big endian\n");
    }

    /***********************************************************/

    return 0;
}

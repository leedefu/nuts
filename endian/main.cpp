#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
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

    return 0;
}

#include <stdio.h>
#include <string.h>

struct sBitEndianCheckStuct
{
    unsigned a:2;
    unsigned b:3;
    unsigned c:2;
    unsigned d:1;
};

// check bit endian
static void checkBitEndian()
{
    sBitEndianCheckStuct s;

    // char result = 3;
    char result = 0x30;
    memcpy(&s, &result, 1);
    printf("a=%d, b=%d, c=%d, d=%d\n", s.a, s.b, s.c, s.d);

    // output:
    // a=0, b=4, c=1, d=0

    // refer to https://www.cnblogs.com/zhangxian/articles/3503460.html
    // https://blog.csdn.net/frank_jb/article/details/79027711
    /*
        Attention: test host is little endian

        [human read] result=0x30:
        bits
        00110000

        C语言的位域中，每个field是严格按照bit地址从低到高排列
        [sBitEndianCheckStuct]在内存中的分布情况 
        low address >>>>>>>>>>>>>>>>>>>>> high address (bits)
        |----|----|----|----|----|----|----|----|
        |----a----|-------b------|----c----|--d-|


        [little endian]: result(0x30) in memory
        low address >>>>>>>>>>>>>>>>>>>>> high address (bits)
        |----|----|----|----|----|----|----|----|
        |  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |
        |    |    |    |    |    |    |    |    |

        [sBitEndianCheckStuct] in memory
        low address >>>>>>>>>>>>>>>>>>>>> high address
        bit
        |----|----|----|----|----|----|----|----|
        |  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |
        |<---a--->|<------b----->|<---c--->|<-d>|

        low address >>>>>>>>>>>>>>>>>>>>> high address
        |----|----|
        |  0 |  0 |
        |<---a--->|
        according to [little endian]:
        [human read] a:
        00
        
                  |----|----|----|               
                  |  0 |  0 |  1 |               
                  |<------b----->|               
        [human read] b:
        100 

                                 |----|----|
                                 |  1 |  0 |
                                 |<---c--->|
        [human read] c:
        01 
                                           |----|
                                           |  0 |
                                           |<-d>|
        [human read] d:
        0 

        a=0;
        b=4;
        c=1;
        d=0;
        

    */
    /*
        [human read] result=0x30:
        bits
        00110000

        C语言的位域中，每个field是严格按照bit地址从低到高排列
        [sBitEndianCheckStuct]在内存中的分布情况 
        low address >>>>>>>>>>>>>>>>>>>>> high address (bits)
        |----|----|----|----|----|----|----|----|
        |----a----|-------b------|----c----|--d-|


        [big endian]: result(0x30) in memory
        low address >>>>>>>>>>>>>>>>>>>>> high address (bits)
        |----|----|----|----|----|----|----|----|
        |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |
        |    |    |    |    |    |    |    |    |

        [sBitEndianCheckStuct] in memory
        low address >>>>>>>>>>>>>>>>>>>>> high address
        bit
        |----|----|----|----|----|----|----|----|
        |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |
        |<---a--->|<------b----->|<---c--->|<-d>|

        low address >>>>>>>>>>>>>>>>>>>>> high address
        |----|----|
        |  0 |  0 |
        |<---a--->|
        according to [little endian]:
        [human read] a:
        00
        
                  |----|----|----|               
                  |  1 |  1 |  0 |               
                  |<------b----->|               
        [human read] b:
        110 

                                 |----|----|
                                 |  0 |  0 |
                                 |<---c--->|
        [human read] c:
        00 
                                           |----|
                                           |  0 |
                                           |<-d>|
        [human read] d:
        0 

        a=0;
        b=6;
        c=0;
        d=0;
        

    */
}

static void checkBytesEndian_1()
{
    /* using union to check endian */

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
}

static void checkBytesEndian_2()
{
    static union { 
        char c[4]; 
        unsigned int myint; 
    } endian_test = { {'l', '?', '?', 'b'} };

#define ENDIANNESS ((char)endian_test.myint)

    printf("ENDIANNESS is %c\n", ENDIANNESS);
    if (ENDIANNESS == 'l') {
        printf("little endian\n");
    }
    else {
        printf("big endian\n");
    }
}

static void checkBytesEndian_3()
{
    // method 3 (different with method 2, same as method 1)
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
}

static void test()
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

static void usage()
{
    printf("usage:\n");
    printf("\tendian bits\n");
    printf("\tendian bytes1\n");
    printf("\tendian bytes2\n");
    printf("\tendian bytes3\n");
    printf("\tendian test\n");
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        usage();
        return 1;
    }

    if (strcmp(argv[1], "bits") == 0) {
        // check bits endian
        checkBitEndian();
    }

    if (strcmp(argv[1], "bytes1") == 0) {
        // check bytes endian
        checkBytesEndian_1();
    }

    if (strcmp(argv[1], "bytes2") == 0) {
        // check bytes endian
        checkBytesEndian_2();
    }

    if (strcmp(argv[1], "bytes3") == 0) {
        // check bytes endian
        checkBytesEndian_3();
    }

    if (strcmp(argv[1], "test") == 0) {
        // test
        test();
    }

    return 0;
}

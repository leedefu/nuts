#include <stdio.h>

extern void tst_unique_ptr();
extern void tst_move_iterator();
extern void tst_inherit_type();
extern void tst_vector_emplace();
extern void tst_lrvalue();

int main(int argc, char* argv[])
{
    printf("Test cpp2.0 new feature\n");

    tst_lrvalue();
    printf("__cplusplus:[%d]\n", __cplusplus);

    // tst_unique_ptr();

    // tst_move_iterator();

    // tst_inherit_type();

    // tst_vector_emplace();


    return 0;
}

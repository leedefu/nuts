#include <stdio.h>

extern void tst_unique_ptr();
extern void tst_move_iterator();
extern void tst_inherit_type();
extern void tst_vector_emplace();

int main(int argc, char* argv[])
{
    printf("test cpp2.0 new feature\n");

    tst_unique_ptr();

    tst_move_iterator();

    tst_inherit_type();

    tst_vector_emplace();


    return 0;
}

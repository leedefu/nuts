#include <stdio.h>
#include <vector>
#include <iostream>

void tst_vector_emplace()
{
    printf("tst_vector_emplace\n");
    std::vector<int> v = {1,2,3};
    for (auto i:v) {
        std::cout<<i<<std::endl;
    }

    int pos = 0;
    std::cout<<"++++++++++++++"<<std::endl;

    v.emplace(v.begin() + pos, 4);
    pos++;

    v.emplace(v.begin() + pos, 5);
    pos++;
    v.emplace(v.begin() + pos, 6);
    for (auto i:v) {
        std::cout<<i<<std::endl;
    }

}

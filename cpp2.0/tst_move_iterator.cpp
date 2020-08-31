#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

void tst_move_iterator()
{
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    printf("tst_move_iterator\n");

    {
        using Iter = std::vector<std::string>::iterator;

        std::vector<std::string> myvec {"first", "sec", "third"};

        std::move_iterator<Iter> begin = std::make_move_iterator(myvec.begin());
        std::move_iterator<Iter> end = std::make_move_iterator(myvec.end());

        std::vector<std::string> othervec(begin.base(), end.base());
        // std::vector<std::string> othervec(myvec.begin(), myvec.end());

        // output
        std::cout<< "myvec:" << std::endl;
        for (auto e : myvec) {
            std::cout<< e << " ";
        }
        std::cout<< std::endl;

        std::cout<< "othervec:" << std::endl;
        for (auto e : othervec) {
            std::cout<< e << " ";
        }
        std::cout<< std::endl;
    }

    std::cout<<"------------------------------------------------"<<std::endl;
    {
        using Iter = std::vector<std::string>::iterator;

        std::vector<std::string> myvec {"first", "sec", "third"};

        std::move_iterator<Iter> begin = std::make_move_iterator(myvec.begin());
        std::move_iterator<Iter> end = std::make_move_iterator(myvec.end());

        std::vector<std::string> othervec(begin, end);

        // output
        std::cout<< "myvec:" << std::endl;
        for (auto e : myvec) {
            std::cout<< e << " ";
        }
        std::cout<< std::endl;

        std::cout<< "othervec:" << std::endl;
        for (auto e : othervec) {
            std::cout<< e << " ";
        }
        std::cout<< std::endl;
    }
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
}

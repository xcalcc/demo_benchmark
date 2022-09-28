#include <iostream>
#include <string>
#include "useBoost.h"

int main()
{
    int a[2] = {0,1};
    int b = a[12];    //AOB

    const int *p1 = nullptr;
    std::cout<<*p1<<std::endl; //NPD
    std::cout<<b<<std::endl; //AOB

    boostTest();
    return 0;
}

#include <iostream>
#include "vector.hpp"

int main(void)
{
    Vector<int> initializerListExample = {1, 2, 3, 4, 5};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(4, 6.66);
    Vector<long double> emptyVector(0);

    std::cout<< "initializerListInit: "<< initializerListExample<< std::endl;
    std::cout<< "lenInit: "<< lenExample<< std::endl;
    std::cout<< "LenFillInit with 6.66 filler: "<< lenFillExample<< std::endl;
    std::cout<< "Empty vector: "<< emptyVector<< std::endl;
}

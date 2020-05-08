#include <iostream>
#include "vector.hpp"

int main(void)
{
    Vector<int> initializerListExample = {1, 2, 3, 4, 5};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(4, 6.66);

    std::cout<< "initializerListInit: "<< initializerListExample<< std::endl;
    std::cout<< "lenInit: "<< lenExample<< std::endl;
}

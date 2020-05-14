#include <iostream>
#include "vector.hpp"

#include "defines.h"

int main(void)
{
    Vector<double> initializerListExample = {1, 2, 3};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(3, 6.66);
    Vector<long double> emptyVector(0);


    std::cout<< "initializerListInit: "<< initializerListExample<< std::endl;
    std::cout<< "lenInit: "<< lenExample<< std::endl;
    std::cout<< "LenFillInit with 6.66 filler: "<< lenFillExample<< std::endl;
    std::cout<< "Empty vector: "<< emptyVector<< std::endl;

    Vector<int> operVecF = {1, 2, 1};
    Vector<int> operVecS = {3, 2, 4};

    std::cout<< "LenFill and InitList angle: "<< lenFillExample.vectorsAngle(initializerListExample)<< std::endl;
    std::cout<< "Vectors *: "<< operVecF * operVecS<< std::endl;
    std::cout<< "Vectors +: "<< operVecF + operVecS<< std::endl;
    std::cout<< "Vectors -: "<< operVecF - operVecS<< std::endl;

    Vector<float> orthVecF = {1, 0, 0};
    Vector<float> orthVecS = {0, 1, 0};
    Vector<float> nonOrthVec = {1, 2, 3};

    std::cout<< "Should be orth: "<< orthVecF.areOrthgonal(orthVecS)<< std::endl;
    std::cout<< "Shouldn't be orth: "<<orthVecF.areCollinear(nonOrthVec)<< std::endl;

    Vector<int> colVecF = {1, 1, 0};
    Vector<int> colVecS = {1, 1, 0};

    std::cout<< "Should be coll: "<< colVecF.areCollinear(colVecS)<< std::endl;
    std::cout<< "Shouldn't be coll: "<< colVecF.areCollinear(operVecF)<< std::endl;

    try {
        orthVecF.areCollinear(lenExample);
    } catch (ZeroDivisionException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    std::cout<< "Pushback: "<< orthVecF<< std::endl;
    orthVecF.pushBack(666);
    std::cout<< "After: "<< orthVecF<< std::endl;

    std::cout<< "PopBack: "<< orthVecF<< std::endl;
    int gotEl = orthVecF.popBack();
    std::cout<< "Popped: "<< orthVecF<< "\t"<< "Element: "<< gotEl<< std::endl;

    std::cout<< "Vector "<< colVecS<< " length is: "<< colVecS.length()<<std::endl;

    std::cout<< "At 1 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(1)<<std::endl;
    std::cout<< "At 2 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(2)<<std::endl;

    try {
        std::cout<< "At 5 el of vector "<< nonOrthVec<< " we have\n"<< nonOrthVec.at(5)<<std::endl;
    } catch (InvalidIndexException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    Vector<double> unitVector = nonOrthVec.getUnitV();
    std::cout<< "\nUnit vector for "<< nonOrthVec<< " is vector "<< unitVector<< std::endl;

    std::cout<< "\nIs vector "<< unitVector<< " unit? Answer: "<< unitVector.isUnitV()<< std::endl;
    std::cout<< "\nIs vector "<< nonOrthVec<< " unit? Answer: "<< nonOrthVec.isUnitV()<< std::endl;

    std::cout<< "\nIs vector "<< nonOrthVec<< " zero? Answer: "<< nonOrthVec.isZeroV()<< std::endl;

    return SUCCESS;
}

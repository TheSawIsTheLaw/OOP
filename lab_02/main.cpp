#include <iostream>
#include "vector.h"

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

    std::cout<< "\nLenFill and InitList angle: "<< lenFillExample.angle(initializerListExample)<< std::endl;

    std::cout<< "\nFor vectors: "<< operVecF<< " and "<< operVecS<< std::endl;
    std::cout<< "Vectors *: "<< operVecF * operVecS<< std::endl;
    std::cout<< "Vectors /: "<< operVecF / operVecS<< std::endl;
    std::cout<< "Vectors +: "<< operVecF + operVecS<< std::endl;
    std::cout<< "Vectors -: "<< operVecF - operVecS<< std::endl;

    Vector<float> orthVecF = {1, 0, 0};
    Vector<float> orthVecS = {0, 1, 0};
    Vector<float> nonOrthVec = {1, 2, 3};

    std::cout<< "\nShould be orth: "<< orthVecF.orthgonal(orthVecS)<< std::endl;
    std::cout<< "Shouldn't be orth: "<<orthVecF.collinear(nonOrthVec)<< std::endl;

    Vector<int> colVecF = {1, 0, 0};
    Vector<int> colVecS = {1, 0, 0};

    std::cout<< "\nShould be coll: "<< colVecF.collinear(colVecS)<< std::endl;
    std::cout<< "Shouldn't be coll: "<< colVecF.collinear(operVecF)<< std::endl;

    try {
        orthVecF.collinear(lenExample);
    } catch (VectorException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    std::cout<< "\nVector "<< colVecS<< " length is: "<< colVecS.length<float>()<<std::endl;

    std::cout<< "\nAt 1 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(1)<<std::endl;
    std::cout<< "At 2 el of vector "<< nonOrthVec<< " we have "<< nonOrthVec.at(2)<<std::endl;

    try {
        std::cout<< "At 5 el of vector "<< nonOrthVec<< " we have\n"<< nonOrthVec.at(5)<<std::endl;
    } catch (VectorException &err) {
        std::cout<< "Error catch:"<< err.what()<< std::endl;
    }

    Vector<double> unitVector = nonOrthVec.getUnitV<double>();
    std::cout<< "\nUnit vector for "<< nonOrthVec<< " is vector "<< unitVector<< std::endl;

    std::cout<< "\nIs vector "<< unitVector<< " unit? Answer: "<< unitVector.isSingleV()<< std::endl;
    std::cout<< "Is vector "<< nonOrthVec<< " unit? Answer: "<< nonOrthVec.isSingleV()<< std::endl;

    std::cout<< "\nIs vector "<< nonOrthVec<< " zero? Answer: "<< nonOrthVec.isZeroV()<< std::endl;
    std::cout<< "Is vector "<< lenExample<< " zero? Answer: "<< lenExample.isZeroV()<< std::endl;

    std::cout<< "\nIncrement to all coords 2 of "<< nonOrthVec<< " is: "<< nonOrthVec.sumEl(2)<<std::endl;
    std::cout<< "Decrement to all coords 2 of "<< nonOrthVec<< " is: "<< nonOrthVec.difEl(2)<<std::endl;
    std::cout<< "Div to all coords 4 of "<< nonOrthVec<< " is: "<< nonOrthVec.divEl(4)<<std::endl;
    std::cout<< "Mul to all coords 4 of "<< nonOrthVec<< " is: "<< nonOrthVec.mulEl(4)<<std::endl;

    std::cout<< "\nFor each: ";
    for (auto elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each &: ";
    for (auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nFor each const &: ";
    for (const auto &elem:orthVecF)
        std::cout<< elem<< " ";

    std::cout<< "\nNonNeg: "<< nonOrthVec<< std::endl;
    nonOrthVec = nonOrthVec.negative();
    std::cout<< "Neg: "<< nonOrthVec<< std::endl;

    nonOrthVec += 1;
    std::cout<< "+= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec -= 1;
    std::cout<< "-= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec *= 2;
    std::cout<< "*= 2 "<< nonOrthVec<< std::endl;

    nonOrthVec /= 2;
    std::cout<< "/= 2 "<< nonOrthVec<< std::endl;

    std::cout<< "The same with phrases... "<< std::endl;

    nonOrthVec.sumEq(1);
    std::cout<< "+= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec.difEq(1);
    std::cout<< "-= 1 "<< nonOrthVec<< std::endl;

    nonOrthVec.mulEq(2);
    std::cout<< "*= 2 "<< nonOrthVec<< std::endl;

    nonOrthVec.divEq(2);
    std::cout<< "/= 2 "<< nonOrthVec<< std::endl;

    std::cout<< nonOrthVec<< " + 3 = "<< nonOrthVec + float(3)<< std::endl;
    std::cout<< nonOrthVec<< " - 3 = "<< nonOrthVec - float(3)<< std::endl;
    std::cout<< nonOrthVec<< " / 3 = "<< nonOrthVec / float(3)<< std::endl;
    std::cout<< nonOrthVec<< " * 3 = "<< nonOrthVec * float(3)<< std::endl;

    int arr[2] = {1, 2};
    Vector<int> arrVec(2, arr);
    std::cout<< arrVec<< std::endl;

    Vector<int> vec = {1, 2, 3};
    Vector<int> vecdel = {3, 2, 1};
    vecdel ^= vec;
    std::cout<< vecdel;

    return SUCCESS;
}

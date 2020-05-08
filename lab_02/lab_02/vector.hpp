#include "vector.h"

//! Distr
template<typename Type>
Vector<Type>::~Vector<Type>() {
    if (values)
        values.reset();
}
//< End

//! Constructors
template<typename Type>
Vector<Type>::Vector() {
    vectorLen = 0;
    allocNewVectorMem(vectorLen);
}

template<typename Type>
Vector<Type>::Vector(int len) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = 0;
}

template<typename Type>
Vector<Type>::Vector(int len, Type element) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = element;
}

template<typename Type>
Vector<Type>::Vector(int len, Type *arrayFrom) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(),
                                   __LINE__, ctime(&currentTime));
    if (!arrayFrom)
        throw InvalidCopyArrayPointer(__FILE__, typeid(*this).name(),
                                      __LINE__, ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(),
                              __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; iterator; iterator++, i++)
        *iterator = arrayFrom[i];
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> arguments) {
    vectorLen = int(arguments.size());
    allocNewVectorMem(vectorLen);

    Iterator<Type> iterator(*this);
    for (auto &currentItem: arguments) {
        *iterator = currentItem;
        iterator++;
    }
}
//< End

//! Get item func
template<typename Type>
Type &Vector<Type>::getItemByIndex(int index) {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorLen)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) {}

    return *iterator;
}
//< End

//! Get item const
template<typename Type>
const Type &Vector<Type>::getItemByIndex(int index) const {
    time_t currentTime = time(NULL);
    if (index < 0 || index >= vectorLen)
        throw InvalidIndexException(__FILE__, typeid(*this).name(),
                                    __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (int i = 0; i < index; i++, iterator++) {}

    return *iterator;
}
//<

//! Overloads

//< End

//! Allocation for Vector
template<typename Type>
void Vector<Type>::allocNewVectorMem(int amount) {
    values.reset();
    // Добавить bad alloc
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}
//< End

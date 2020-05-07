#include "vector.h"

template<typename Type>
Vector<Type>::~Vector<Type>() {
    if (values)
        values.reset();
}

template<typename Type>
Vector<Type>::Vector() {
    vectorLen = 0;
    allocNewVectorMem(vectorLen);
}

template<typename Type>
Vector<Type>::Vector(int len) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(), __LINE__,
                                   ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = 0;
}

template<typename Type>
Vector<Type>::Vector(int len, Type element) {
    time_t currentTime = time(NULL);
    if (len < 0)
        throw EmptyVectorException(__FILE__, typeod(*this).name(), __LINE__,
                                   ctime(&currentTime));

    allocNewVectorMem(len);
    if (!values)
        throw MemoryException(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));

    Iterator<Type> iterator(*this);
    for (; iterator; iterator++)
        *iterator = element;
}

template<typename Type>
void Vector<Type>::allocNewVectorMem(int amount) {
    values.reset();
    // Добавить bad alloc
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}
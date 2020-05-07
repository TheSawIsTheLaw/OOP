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
void Vector<Type>::allocNewVectorMem(int amount) {
    values.reset();
    // Добавить bad alloc
    std::shared_ptr<Type> temp(new Type[amount], std::default_delete<Type[]>());
    values = temp;
}

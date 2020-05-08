#ifndef VECTORBASE_H
#define VECTORBASE_H

//template<typename Type>
//class Iterator;

class VectorBase {
public:
    VectorBase();
    VectorBase(const VectorBase &);
    ~VectorBase();

    bool isEmpty() const;
    int size() const;

protected:
    int vectorSize = 0;
};

#endif // VECTORBASE_H

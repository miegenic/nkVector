#ifndef NKVECTOR_NKVECTOR_H
#define NKVECTOR_NKVECTOR_H

class nkVector{
private:
    unsigned size; //Size of the vector (currently)
    unsigned maximum; //Max size of the vector (increases if allowed)
    unsigned multiplier = 2;
    int *array;

    void allocate_new();
    void clear();
    void syncEnd();
public:
    unsigned begin = 0;
    unsigned end = size;
    nkVector();
    nkVector(unsigned maximum);
    nkVector(unsigned maximum, unsigned multiplier);
    nkVector(const nkVector&);

    ~nkVector();

    void push_back(int);
    void deleteLast();
    void deleteFirst();

    unsigned vSize();
    unsigned vMax();
    unsigned vMultiplier();

    void changeMultiplier(unsigned multiplier);
    void changeMaximum(unsigned maximum);

    int operator[](int index);
    void operator>>(int value);

};

#endif //NKVECTOR_NKVECTOR_H

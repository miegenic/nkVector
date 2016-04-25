#include "nkVector.h"

nkVector::nkVector() {
    maximum = 1;
    array = new int[maximum];
    size = 0;
};

nkVector::nkVector(unsigned vMaximum) {
    maximum = vMaximum;
    array = new int[maximum];
    size = 0;
};

nkVector::nkVector(unsigned vMaximum, unsigned vMultiplier) {
    maximum = vMaximum;
    array = new int[maximum];
    size = 0;
    multiplier = vMultiplier;
};

nkVector::nkVector(const nkVector&){};

void nkVector::clear() {
    delete[] array;
}

nkVector::~nkVector() {
    delete[] array;
};

void nkVector::syncEnd() {
    end = size;
}

void nkVector::push_back(int value) {
    if(size + 1 > maximum) {
        allocate_new();
    }
    array[size] = value;
    size++;
    syncEnd();
};

int nkVector::operator[](int index) {
    if(index < size) {
        return array[index];
    } else {
        return array[size];
    }
};

void nkVector::operator>>(int value) {
    if(size + 1 > maximum) {
        allocate_new();
    }
    array[size] = value;
    size++;
    syncEnd();
};

void nkVector::allocate_new() {
    if(maximum == 1) {
        maximum++;
    } else {
        maximum*=multiplier;
    }
    int *tempArray = new int[maximum];
    for(int i = 0; i < size; i++) {
        tempArray[i] = array[i];
    }
    delete[] array;
    array = tempArray;
};

void nkVector::deleteFirst() {
    if(size != 0) {
        int *tempArray = new int[maximum];
        for(int i = 1; i < size; i++) {
            tempArray[i-1] = array[i];
        }
        delete[] array;
        array = tempArray;
        size--;
        syncEnd();
    }
};

void nkVector::deleteLast() {
    if(size != 0) {
        int *tempArray = new int[maximum];
        for(int i = 0; i < size-1; i++) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        size--;
        syncEnd();
    }
};

unsigned nkVector::vSize() {
    return size;
};

unsigned nkVector::vMax() {
    return maximum;
};

unsigned nkVector::vMultiplier() {
    return multiplier;
};

void nkVector::changeMaximum(unsigned vMaximum) {
    if(vMaximum < maximum) {
        if(vMaximum > size) {
            maximum = vMaximum;
            int *tempArray = new int[vMaximum];
            for(int i = 0; i < size; i++) {
                tempArray[i] = array[i];
            }
            delete[] array;
            array = tempArray;
            size--;
            syncEnd();
        }
    } else {
        maximum = vMaximum;
        int *tempArray = new int[vMaximum];
        for(int i = 0; i < size; i++) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        size--;
        syncEnd();
    }
}

void nkVector::changeMultiplier(unsigned vMultiplier) {
    if(vMultiplier > 2) {
        multiplier = vMultiplier;
    }
}
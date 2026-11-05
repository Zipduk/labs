#include <iostream>

class Vec {
private:

    int* data_;
    int size_;
    int capacity_;

    void reallocate(int newCapacity);

public:

    Vec();

    Vec(const int* arr, int size);


};
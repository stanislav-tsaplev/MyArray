#pragma once
#include <iostream>
#include <ostream>
using namespace std;


class int_array
{
    int* _data;
    int _size;

    int_array()
        : _data(NULL), _size(0)
    {
    }

public:
    int_array(int size);

    void init();
    int size();

    int& operator[](int index);

    int_array& subarray(int begin, int end);
    int_array& copy();

    friend ostream& operator<<(ostream& os, const int_array& array);
};


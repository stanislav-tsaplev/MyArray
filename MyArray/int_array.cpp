#include "int_array.h"


int_array::int_array(int size)
    : _size(size)
{
    _data = new int[size];
}

void int_array::init()
{
    for (int i = 0; i < _size; i++)
        _data[i] = 0;
}

int& int_array::operator[](int index)
{
    return _data[index];
}

int int_array::size()
{
    return _size;
}

int_array& int_array::subarray(int begin, int end)
{
    int_array* subarray = new int_array();
    subarray->_data = _data + begin;
    subarray->_size = end - begin;

    return *subarray;
}

int_array& int_array::copy()
{
    int_array* copy = new int_array(_size);
    for (int i = 0; i < _size; i++)
        copy->_data[i] = _data[i];

    return *copy;
}

ostream& operator<<(ostream& os, const int_array& array)
{
    for (int i = 0; i < array._size; i++)
        os << array._data[i] << ' ';

    return os;
}
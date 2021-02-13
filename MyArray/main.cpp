#include <iostream>
#include <ostream>
using namespace std;


struct IntArray
{
    int* _data;
    int _size;

    IntArray()
        : _data(NULL), _size(0)
    {
    }

public:
    IntArray(int size)
        : _size(size)
    {
        _data = new int[size];
    }

    void init()
    {
        for (int i = 0; i < _size; i++)
            _data[i] = 0;
    }

    int& operator[](int index)
    {
        return _data[index];
    }

    int size()
    {
        return _size;
    }

    IntArray& subarray(int begin, int end)
    {
        IntArray* subarray = new IntArray();
        subarray->_data = _data + begin;
        subarray->_size = end - begin;

        return *subarray;
    }

    IntArray& copy()
    {
        IntArray* copy = new IntArray(_size);
        for (int i = 0; i < _size; i++)
            copy->_data[i] = _data[i];

        return *copy;
    }

    friend ostream& operator<<(ostream& os, const IntArray& array)
    {
        for (int i = 0; i < array._size; i++)
            os << array._data[i] << ' ';

        return os;
    }
};

void merge_sort(IntArray array)
{
    if (array.size() < 2)
        return;

    IntArray left_array = array.subarray(0, array.size() / 2).copy();
    IntArray right_array = array.subarray(array.size() / 2, array.size()).copy();

    merge_sort(left_array);
    merge_sort(right_array);

    int index = 0, left_index = 0, right_index = 0;
    while (left_index < left_array.size() && right_index < right_array.size())
    {
        if (left_array[left_index] < right_array[right_index])
            array[index++] = left_array[left_index++];
        else
            array[index++] = right_array[right_index++];
    }

    while (left_index < left_array.size())
        array[index++] = left_array[left_index++];

    while (right_index < right_array.size())
        array[index++] = right_array[right_index++];
}

void merge_sort(int array[], int size)
{
    if (size < 2)
        return;

    int* left_array = array;
    int left_size = size / 2;

    int* right_array = array + size / 2;
    int right_size = size - size / 2;

    merge_sort(left_array, left_size);
    merge_sort(right_array, right_size);

    int* temp_array = new int[size];

    int index = 0, left_index = 0, right_index = 0;
    while (left_index < left_size && right_index < right_size)
    {
        if (left_array[left_index] < right_array[right_index])
            temp_array[index++] = left_array[left_index++];
        else
            temp_array[index++] = right_array[right_index++];
    }

    while (left_index < left_size)
        temp_array[index++] = left_array[left_index++];

    while (right_index < right_size)
        temp_array[index++] = right_array[right_index++];

    for (int i = 0; i < size; i++)
        array[i] = temp_array[i];
}

int main()
{
    //int classic_array[] = { 3, 15, 10, 20, 19, 2, 6, -11 };
    //for (int i = 0; i < 8; i++)
    //    cout << classic_array[i] << ' ';
    //cout << endl;

    //merge_sort(classic_array, 8);

    //for (int i = 0; i < 8; i++)
    //    cout << classic_array[i] << ' ';
    //cout << endl;


    IntArray my_array(8);
    my_array[0] = 3;
    my_array[1] = 15;
    my_array[2] = 10;
    my_array[3] = 20;
    my_array[4] = 19;
    my_array[5] = 2;
    my_array[6] = 6;
    my_array[7] = -11;
    
    cout << my_array << endl;

    merge_sort(my_array);

    cout << my_array << endl;
}

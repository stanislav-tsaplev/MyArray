#include <iostream>
#include <ostream>
using namespace std;


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
    int classic_array[] = { 3, 15, 10, 20, 19, 2, 6, -11 };
    for (int i = 0; i < 8; i++)
        cout << classic_array[i] << ' ';
    cout << endl;

    merge_sort(classic_array, 8);

    for (int i = 0; i < 8; i++)
        cout << classic_array[i] << ' ';
    cout << endl;
}

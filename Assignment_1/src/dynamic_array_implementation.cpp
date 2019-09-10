#include "../include/dynamic_array.hpp"

using namespace std;

//Given just for reference. Only the class name and function names should match.
class dynamic_array_implementation : public dynamic_array
{
private:
    int size;
    int capacity;
    int *arr;
    double increase_factor;
    double decrease_factor;

public:
    dynamic_array_implementation();
    int get_size();
    int get_capacity();
    void set_increase_factor_table_size(double);
    void set_load_factor_reduction(double);
    void append(int);
    void pop();
    int get(int);
    ~dynamic_array_implementation();
};

dynamic_array_implementation::dynamic_array_implementation()
{
    size = 0;
    capacity = 0;
    increase_factor = 2;
    decrease_factor = 0.25;
}

int dynamic_array_implementation::get_size()
{
    return size;
}

int dynamic_array_implementation::get_capacity()
{
    return capacity;
}

void dynamic_array_implementation::set_increase_factor_table_size(double increase_factor)
{
    this->increase_factor = increase_factor;
    return;
}

void dynamic_array_implementation::set_load_factor_reduction(double decrease_factor)
{
    this->decrease_factor = decrease_factor;
    return;
}

void dynamic_array_implementation::append(int element)
{
    if (capacity == 0)
    {
        arr = new int[++capacity];
    }

    if (size == capacity)
    {
        int *temp = new int[capacity = (int)(capacity * increase_factor)];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size++] = element;
    return;
}

void dynamic_array_implementation::pop()
{
    if (!size)
        return;

    if (!--size)
    {
        delete[] arr;
        capacity = 0;
        return;
    }

    if (size <= capacity * decrease_factor)
    {
        int *temp = new int[capacity = (int)(capacity * increase_factor * decrease_factor)];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    return;
}

int dynamic_array_implementation::get(int index)
{
    if (index >= 0 && index < size)
        return arr[index];

    return -1;
}

dynamic_array_implementation::~dynamic_array_implementation()
{
    if (capacity > 0)
    {
        delete[] arr;
    }
}
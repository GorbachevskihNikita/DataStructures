#include <stdexcept>
#include <iostream>

template <class T>
class Array {
private:
    T *_array;
    size_t _size;
public:
    Array(const size_t &InSize)
    {
        _size = InSize > 0 ? InSize : throw std::invalid_argument("Array size must be greater than 0");
        _array = new T[_size];
    };

    Array(const Array &InArray)
    {
        _array = InArray;
        _size = InArray._size;
    }

    Array& operator=(const Array &InArray)
    {
        if (this != &InArray) {
            T *newArray = new T[InArray._size];
            std::copy(InArray._array, InArray._array + InArray._size, newArray);
            delete[] _array;
            _array = newArray;
            _size = InArray._size;
        }
        return *this;
    }

    ~Array()
    {
        delete[] _array;
    };

    size_t getSize() const
    {
        return _size;
    }

    T& operator[](int index) const
    {
        if (index < 0 || index > _size) throw std::out_of_range("Index out of range");
        return _array[index];
    };

    bool& operator!=(const Array& array) const
    {
        return this != array;
    }

    bool& operator==(const Array& array) const
    {
        return this == array;
    }
};

int main()
{
    Array<int> array1(5);
    Array<int> array2(5);
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    array2[3] = 4;
    array2[4] = 5;
    array1 = array2;
    std::cout << array1.getSize() << std::endl;
    for (int i = 0; i < array1.getSize(); ++i)
    {
        std::cout << array1[i] << std::endl;
    }
    return 0;
}
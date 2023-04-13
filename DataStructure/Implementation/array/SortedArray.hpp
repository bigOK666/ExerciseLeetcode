// 大小固定的有序数组，支持动态增删改，而且可以合并为一个数组

#include <iostream>
#include <stdexcept>

const int capacity = 8;

class FixedSortedArray
{
private:
    int m_size;
    int m_data[capacity];
    int findPosition(int value) const
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (m_data[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

public:
    FixedSortedArray() : m_size(0) {}
    ~FixedSortedArray() {}

    void add(int value)
    {
        if (m_size >= capacity)
        {
            throw std::out_of_range("array is full");
        }

        int position = m_size;
        for (int i = m_size - 1; i >= 0; --i)
        {
            if (m_data[i] > value)
            {
                m_data[i + 1] = m_data[i];
                position = i;
            }
            else
            {
                break;
            }
        }
        m_data[position] = value;
        ++m_size;
    }

    void remove(int value)
    {
        int position = findPosition(value);
        if (position < 0)
        {
            return;
        }

        for (int i = position; i < m_size - 1; ++i)
        {
            m_data[i] = m_data[i + 1];
        }

        --m_size;
    }

    void modify(int oldValue, int newValue)
    {
        int position = findPosition(oldValue);
        if (position < 0)
        {
            throw std::invalid_argument("no such value");
        }
        remove(oldValue);
        add(newValue);
    }

    int size() const
    {
        return m_size;
    }

    int operator[](int index) const
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }
};

void merge(int arr1[], int m, int arr2[], int n, int mergedArr[])
{
    int indexArr1 = 0;
    int indexArr2 = 0;
    int indexMergedArr = 0;

    while (indexArr1 < m && indexArr2 < n)
    {
        if (arr1[indexArr1] < arr2[indexArr2])
        {
            mergedArr[indexMergedArr] = arr1[indexArr1];
            ++indexArr1;
        }
        else
        {
            mergedArr[indexMergedArr] = arr2[indexArr2];
            ++indexArr2;
        }
        ++indexMergedArr;
    }

    while (indexArr1 < m)
    {
        mergedArr[indexMergedArr] = arr1[indexArr1];
        ++indexArr1;
        ++indexMergedArr;
    }

    while (indexArr2 < n)
    {
        mergedArr[indexMergedArr] = arr2[indexArr2];
        ++indexArr2;
        ++indexMergedArr;
    }
}
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class SortingAlgo
{
public:
    template<typename T>
    static void BubbleSort(vector<T>& data)
    {
        int n = data.size();
        bool is_sorted = false;
        // while array not sorted
        while (!is_sorted)
        {
            is_sorted = true;
            // Search for adjacent elements that are in the wrong order
            for (int i = 1; i < n; ++i)
            {
                // If adjacent elements are in the wrong order
                if (data[i - 1] > data[i])
                {
                    // Swap them
                    std::swap(data[i - 1], data[i]);
                    is_sorted = false;
                }
            }
            --n;
        }
        // check sorted
        assert(std::is_sorted(data.begin(), data.end()) == true);
    }

    template<typename T>
    static void InsertionSort(vector<T>& data)
    {
        int n = data.size();
        for (int i = 1; i < n; ++i)
        {
            // Move element i to the corresponding position
            // in the sorted part of the array.
            T x = data[i];
            int j = i;
            for (; j > 0 && data[j - 1] > x; --j)
            {
                data[j] = data[j - 1];
            }
            data[j] = x;
        }
        // check sorted
        assert(is_sorted(data.begin(), data.end()) == true);
    }

    template<typename T>
    static void MergeSort(vector<T>& data)
    {
        recursiveMergeSort(data, 0, data.size());
        // check sorted
        assert(is_sorted(data.begin(), data.end()) == true);
    }

private:

    template<typename T>
    static void recursiveMergeSort(vector<T>& data, int left, int right)
    {
        if (left + 1 < right)
        {
            int middle = (left + right) / 2;

            // Sort first and second halves
            recursiveMergeSort(data, left, middle);
            recursiveMergeSort(data, middle, right);

            // Merge
            int i = 0; // left side iterator
            int j = 0; // right side iterator
            vector<T> temp(right - left); // temp array

            // While there are elements on both the right and left side
            while (left + i < middle && middle + j < right)
            {
                // If left-side element less than right-side
                if (data[left + i] < data[middle + j])
                {
                    temp[i + j] = data[left + i]; // add it to result
                    ++i;
                }
                else // If right-side element less than left-side
                {
                    temp[i + j] = data[middle + j]; // add it to result
                    ++j;
                }
            }

            // If left only the elements on the left side
            while (left + i < middle)
            {
                temp[i + j] = data[left + i]; // add them to result
                ++i;
            }
            // If left only the elements on the right side
            while (middle + j < right)
            {
                temp[i + j] = data[middle + j];// add them to result
                ++j;
            }

            copy(temp.begin(), temp.end(), data.begin() + left); // copy result
        }
    }
};
#endif // SORTINGALGO_H

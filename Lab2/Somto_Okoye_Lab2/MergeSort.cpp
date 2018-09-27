//#include "MergeSort.h"

//#include <algorithm>
//#include <cassert>
//using namespace std;

//MergeSort::MergeSort() : Algorithm()
//{
//}


//MergeSort::~MergeSort()
//{
//}

//void MergeSort::Execute(vector<TYPENAME>& data)
//{
//	recursiveMergeSort(data, 0, data.size());
//	// check sorted
//	assert(is_sorted(data.begin(), data.end()) == true);
//}

//string MergeSort::GetName() const
//{
//	return "Merge Sort";
//}

//void MergeSort::recursiveMergeSort(vector<TYPENAME>& data, size_t left, size_t right)
//{
//	if (left + 1 < right)
//	{
//		size_t middle = (left + right) / 2;

//		// Sort first and second halves
//		recursiveMergeSort(data, left, middle);
//		recursiveMergeSort(data, middle, right);

//		// Merge
//		size_t i = 0; // left side iterator
//		size_t j = 0; // right side iterator
//		vector<TYPENAME> temp(right - left); // temp array

//		// While there are elements on both the right and left side
//		while (left + i < middle && middle + j < right)
//		{
//			// If left-side element less than right-side
//			if (data[left + i] < data[middle + j])
//			{
//				temp[i + j] = data[left + i]; // add it to result
//				++i;
//			}
//			else // If right-side element less than left-side
//			{
//				temp[i + j] = data[middle + j]; // add it to result
//				++j;
//			}
//		}

//		// If left only the elements on the left side
//		while (left + i < middle)
//		{
//			temp[i + j] = data[left + i]; // add them to result
//			++i;
//		}
//		// If left only the elements on the right side
//		while (middle + j < right)
//		{
//			temp[i + j] = data[middle + j];// add them to result
//			++j;
//		}

//		copy(temp.begin(), temp.end(), data.begin() + left); // copy result
//	}

//}

//#include "InsertionSort.h"

//#include <algorithm>
//#include <cassert>
//using namespace std;

//InsertionSort::InsertionSort(): Algorithm()
//{
//}


//InsertionSort::~InsertionSort()
//{
//}

//void InsertionSort::Execute(vector<TYPENAME>& data)
//{
//	size_t n = data.size();
//	for (size_t i = 1; i < n; ++i)
//	{
//		// Move element i to the corresponding position
//		// in the sorted part of the array.
//		TYPENAME x = data[i];
//		size_t j = i;
//		for (; j > 0 && data[j - 1] > x; --j)
//		{
//			data[j] = data[j - 1];
//		}
//		data[j] = x;
//	}
//	// check sorted
//	assert(is_sorted(data.begin(), data.end()) == true);
//}

//string InsertionSort::GetName() const
//{
//	return "Insertion Sort";
//}

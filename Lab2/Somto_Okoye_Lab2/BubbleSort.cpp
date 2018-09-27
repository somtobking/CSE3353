//#include "BubbleSort.h"

//#include <algorithm>
//#include <cassert>
//using namespace std;

//BubbleSort::BubbleSort(): Algorithm()
//{
//}


//BubbleSort::~BubbleSort()
//{
//}

//void BubbleSort::Execute(vector<TYPENAME>& data)
//{
//	size_t n = data.size();
//	bool is_sorted = false;
//	// while array not sorted
//	while (!is_sorted)
//	{
//		is_sorted = true;
//		// Search for adjacent elements that are in the wrong order
//		for (size_t i = 1; i < n; ++i)
//		{
//			// If adjacent elements are in the wrong order
//			if (data[i - 1] > data[i])
//			{
//				// Swap them
//				std::swap(data[i - 1], data[i]);
//				is_sorted = false;
//			}
//		}
//		--n;
//	}
//	// check sorted
//	assert(std::is_sorted(data.begin(), data.end()) == true);
//}

//string BubbleSort::GetName() const
//{
//	return "Bubble Sort";
//}

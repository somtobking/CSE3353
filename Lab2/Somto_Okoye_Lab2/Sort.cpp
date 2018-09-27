//#include <iostream>
//#include <fstream>
//using namespace std;

//#include "Sort.h"


//Sort::Sort(): algo(nullptr)
//{
//}

//Sort::~Sort()
//{
//	if (algo)
//		delete algo;
//}

//void Sort::Load(string filename)
//{
//	data.clear();
//	ifstream in(filename);
//	TYPENAME i;
//	while (in >> i)
//		data.push_back(i);
//}

//void Sort::Execute()
//{
//	if (algo)
//	{
//		sorted = data;
//		start = high_resolution_clock::now();
//		algo->Execute(sorted);
//		end = high_resolution_clock::now();
//	}
//}

//void Sort::Display()
//{
//	for (const auto& i : sorted)
//		cout << i << endl;
//}

//void Sort::Stats()
//{
//	if (algo)
//	{
//		cout << algo->GetName() << endl;
//		duration<double> elapsed = duration_cast<duration<double>>(end - start);
//		cout << "Time: " << elapsed.count() << "s" << endl;
//		cout << "DataSet Size: " << data.size() << endl << endl;
//	}
//}

//void Sort::Select(int algoId)
//{
//	if (algo)
//		delete algo;

//	if (algoId == BUBBLE)
//		algo = new BubbleSort();
//	else if (algoId == INSERTION)
//		algo = new InsertionSort();
//	else if (algoId == MERGE)
//		algo = new MergeSort();
//}

//void Sort::Save(string filename)
//{
//	ofstream out(filename);
//	if (out)
//	{
//		for (const auto& i : sorted)
//			out << i << endl;
//	}
//}

//void Sort::Configure()
//{
//}

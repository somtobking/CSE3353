/*
 Somto Okoye
 Lab 1- CSE 3353
 */

#include <iostream>
#include <string>

using namespace std;

#include "Sort.h"

const int TYPE_COUNT = 4;
const string DATA_SET_TYPE[TYPE_COUNT] =
{
    "Random",
    "Reversed",
    "Unique",
    "Partial"
};

const int SIZE_COUNT = 4;
const string DATA_SET_SIZE[SIZE_COUNT] =
{
    "10",
    "1000",
    "10000",
    "100000"
};

int main()
{
    Sort sort;
    for (const auto& algo: ALGO_TYPE)
    {
        cout << "***************************" << endl;

        sort.Select(algo);

        for (const auto& type: DATA_SET_TYPE)
        {
            for (const auto& size: DATA_SET_SIZE)
            {
                //path to dataset and input those generated txt files
                string dataSetName = string("DataSet/") + type + "_" + size + ".txt";

                sort.Load(dataSetName);
                sort.Execute();
                cout << type << endl;
                sort.Stats();

                //sort.Display();

                //output the sorted array to one document called output.txt
                string output = string("Output.txt");
                sort.Save(output);

            }
        }
    }

    return 0;
}

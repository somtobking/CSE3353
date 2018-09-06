#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int TYPE_COUNT = 4;
const string DATA_SET_TYPE[TYPE_COUNT] =
{
    "random",
    "reversed",
    "unique",
    "partial"
};

const int SIZE_COUNT = 4;
const string DATA_SET_SIZE[TYPE_COUNT] =
{
    "10",
    "1000",
    "10000",
    "100000"
};

void genRandom(vector<int>& data, int size)
{
    data.clear();
    data.resize(size);

    for (int i = 0; i < size; ++i)
        data[i] = i + 1;
    random_shuffle(data.begin(), data.end());
}

void genReversed(vector<int>& data, int size)
{
    data.clear();
    data.resize(size);

    for (int i = 0; i < size; ++i)
        data[size - i - 1] = i + 1;
}

void genUnique(vector<int>& data, int size)
{
    data.clear();
    data.resize(size);

    int i = 0;
    for (int i = 0; i < size; i += 5)
    {
        for (int j = 0; j < 5 && i + j < size; ++j)
        {
            data[i + j] = i + 1;
        }
    }
    random_shuffle(data.begin(), data.end());
}

void genPartial(vector<int>& data, int size)
{
    data.clear();
    data.resize(size);

    for (int i = 0; i < size; ++i)
        data[i] = i + 1;

    int nRand = size * 30 / 100;
    for (int i = 0; i < nRand; ++i)
    {
        int a = rand() % size;
        int b = rand() % size;

        swap(data[a], data[b]);
    }
}

int main()
{
    vector<int> data;
    for (int i = 0; i < TYPE_COUNT; ++i)
    {
        for (int j = 0; j < SIZE_COUNT; ++j)
        {
            string dataSetName = /*string("DataSet/") +*/ DATA_SET_TYPE[i] + "_" + DATA_SET_SIZE[j] + ".txt";
            int size = stoi(DATA_SET_SIZE[j]);

            if (DATA_SET_TYPE[i] == "random")
                genRandom(data, size);
            else if (DATA_SET_TYPE[i] == "reversed")
                genReversed(data, size);
            else if (DATA_SET_TYPE[i] == "unique")
                genUnique(data, size);
            else if (DATA_SET_TYPE[i] == "partial")
                genPartial(data, size);

            ofstream out(dataSetName);
            for (const auto& i: data)
                out << i << endl;
            out.close();
        }
    }
    return 0;
}

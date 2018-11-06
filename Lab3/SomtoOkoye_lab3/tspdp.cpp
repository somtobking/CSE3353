#include "tspdp.h"

#define MAXVALUE 4 //Change Max Nodes here

float ary[1000][1000],completed[1000],n,cost=0;

using namespace std;


int TspDp::least(int c)
{
    int nc=MAXVALUE;
    float min=MAXVALUE,kmin;

    for(int i=0;i < n;i++)
    {
        if((ary[c][i]!=0)&&(completed[i]==0))
            if(ary[c][i]+ary[i][c] < min)
            {
                min=ary[i][0]+ary[c][i];
                kmin=ary[c][i];
                nc=i;
            }
    }

    if(min!=MAXVALUE)
        cost+=kmin;

    return nc;
}

void TspDp::mincost(int city)
{
    int i,ncity;

    completed[city]=1;

    cout<<city+1<<"--->";
    ncity=least(city);

    if(ncity==MAXVALUE)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];

        return;
    }

    mincost(ncity);
}

vector<vector<float>> TspDp::getData(string filename)
{
    //Reads the file and stores the result
    ifstream inFile;
    float x;

    vector<vector<float> > data;
    ifstream infile(filename);

    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );
        vector <float> record;

        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' )) break;
            record.push_back(stof(s));
        }

        data.push_back(record);
    }
    if (!infile.eof())
    {
        cerr << "No data\n";
    }
    return data;
}

int TspDp::execute()
{

    vector<vector<float> > data = getData("input.txt");
    n = data.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<data[i].size();j++)
        {
            if(i>j)
                ary[(int)(data[i][0])-1][j] = data[i][j+1];
            else
                ary[(int)(data[i][0])-1][j+1] = data[i][j+1];
        }
    }

    cout<<"Path of Nodes(DP): ";
    mincost(0); //passing 0 because starting vertex

    cout<<"\nShortest Path(DP): "<<abs(cost)<<endl;

    auto startDP = high_resolution_clock::now();
    auto stopDP = high_resolution_clock::now();
    auto durationDP = duration_cast<microseconds>(stopDP - startDP);
    cout << "Dynamic Programming Algorithm Execution Time : " << durationDP.count()<<" miliseconds" << endl;
    cout << "*****************************" << endl;

    return 0;
}


void TspDp::printAlgo()
{
    cout << "Travelling Salesman Dynamic Programming" << endl;
}


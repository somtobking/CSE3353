//
// Created by Somto Okoye on 2018-11-28.
//

#include "map.h"


using namespace std;

int Map::getVertex(){
    return numOfVertex;
}

void Map::readDataFile(string filename)
{
    ifstream inFile;
    inFile.open(filename);

    if(inFile.is_open()){
        int id;
        float id_cod;
        string file;
        while(!inFile.eof()){
            int pos = 0;
            getline(inFile, file);
            if(file.size() > 0) {
                Node n;
                pos = file.find(",");
                id = stoi(file.substr(0, pos));
                file.erase(0, pos + 1);
                n.id = id;
                for (int i = 0; i < 3; i++) {
                    pos = file.find(",");
                    id_cod = stof(file.substr(0, pos));
                    file.erase(0, pos + 1);
                    n.coordinates[i] = id_cod;
                }
                nodes.push_back(n);
                numOfVertex++;
            }

        }
        inFile.close();
    }
    else{
        cout << "Input File: " << filename << "did not open" << endl;
        exit(-1);
    }
}

double Map::getDis(int d1, int d2)
{
    Node node1 = nodes[d1 - 1];
    Node node2 = nodes[d2 - 1];

    return sqrt(pow(node1.coordinates[0]-node2.coordinates[0],2) +
    pow(node1.coordinates[1]-node2.coordinates[1],2) +
    pow(node1.coordinates[2]-node2.coordinates[2],2));

}


#include<fstream>
#include<iostream>
#include "graph_level1.h"
using namespace std;
#pragma warning disable:4996
void Graph::LoadMatrix(std::string& filename) {
    ifstream file(filename);

    int size;
    file >> size;
    this->size = size;

    graph = new int* [size];
    for (int i = 0; i < size; ++i)
        graph[i] = new int[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> graph[i][j];
        }
    }

    dist = new int[size];
    s = new int[size];

    file.close();
}
void Graph::PrintMatrix() {
    //cout <<"this is printmatrix" << endl;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
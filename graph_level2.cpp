#include<fstream>
#include<iostream>
#include "graph_level2.h"
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
    //cout << "this is printmatrix" << endl;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int Graph::GetSize()       // 행렬의 크기(SIZE) 반환
{
    return size;
}
void Graph::PrintShortestPathWeight(int s)     // 시작 정점 s로부터 나머지 vertex까지의 최단 경로의 가중치 합 출력
{
    //cout << "this is printShortestPathWeight" << endl;
    for (int i = 0; i < size; i++) {
        this->s[i] = false;   //s는 해당정점 방문여부를 true/false로 저장
        dist[i] = graph[s][i];   //시작정점s에서 인접정점의 거리를 dist에 저장
    }
    this->s[s] = true;
    //this->dist[s] = 0;


    for (int i = 0; i < size - 2; i++) {
        int shortestPathIndex = 0;
        int min = 999;
        for (int j = 0; j < size; j++) {
            if (this->s[j] == false && min > dist[j]) {
                min = dist[j];
                shortestPathIndex = j;
            }
        }
        int u = shortestPathIndex;
        this->s[u] = true;

        for (int k = 0; k < size; k++) {
            if (this->s[k] == false && dist[u] + graph[u][k] < dist[k]) {
                dist[k] = dist[u] + graph[u][k];
            }
        }
    }

    for (int l = 0; l < size; l++) {
        cout << dist[l] << endl;
    }
}
#include<fstream>
#include<iostream>
#include "graph_level3.h"
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

    path = new int* [size];
    for (int i = 0; i < size; ++i)
        path[i] = new int[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            path[i][j] = -1;
        }
    }

    file.close();
}
void Graph::PrintMatrix() {
    cout << "this is printmatrix" << endl;
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
void Graph::PrintShortestPath(int s)       // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
{
    //인접행렬 복사
    int** temp = new int* [size];
    for (int i = 0; i < size; ++i)
        temp[i] = new int[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = graph[i][j];
        }
    }

    //k=거쳐가는 노드, i=출발노드, j=도착노드
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //출발노드->도착노드 vs 출발노드->거쳐가는k노드->도착노드j
                if (temp[i][j] > temp[i][k] + temp[k][j]) {
                    temp[i][j] = temp[i][k] + temp[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i < size; i++) {
        printf("%d ", s);
        PrintShortestPath(s, i);
        printf("%d\n", i);
    }
}
void Graph::PrintShortestPath(int start, int end)
{
    if (path[start][end] != -1) {
        PrintShortestPath(start, path[start][end]);   //start에서 경유하는 노드까지 경로 검사
        printf("%d ", path[start][end]);
        PrintShortestPath(path[start][end], end);   //경유노드에서 end까지 경로 검사
    }
}
void Graph::PrintShortestPathWeight(int s)     // 시작 정점 s로부터 나머지 vertex까지의 최단 경로의 가중치 합 출력
{
    cout << "this is printShortestPathWeight" << endl;
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
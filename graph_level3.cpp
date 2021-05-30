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
int Graph::GetSize()       // ����� ũ��(SIZE) ��ȯ
{
    return size;
}
void Graph::PrintShortestPath(int s)       // ���� ���� s�κ��� ������ vertex������ �ִ� ��� ���
{
    //������� ����
    int** temp = new int* [size];
    for (int i = 0; i < size; ++i)
        temp[i] = new int[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = graph[i][j];
        }
    }

    //k=���İ��� ���, i=��߳��, j=�������
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //��߳��->������� vs ��߳��->���İ���k���->�������j
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
        PrintShortestPath(start, path[start][end]);   //start���� �����ϴ� ������ ��� �˻�
        printf("%d ", path[start][end]);
        PrintShortestPath(path[start][end], end);   //������忡�� end���� ��� �˻�
    }
}
void Graph::PrintShortestPathWeight(int s)     // ���� ���� s�κ��� ������ vertex������ �ִ� ����� ����ġ �� ���
{
    cout << "this is printShortestPathWeight" << endl;
    for (int i = 0; i < size; i++) {
        this->s[i] = false;   //s�� �ش����� �湮���θ� true/false�� ����
        dist[i] = graph[s][i];   //��������s���� ���������� �Ÿ��� dist�� ����
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
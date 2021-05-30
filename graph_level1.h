#include<iostream>
using namespace std;
class Graph
{
private:
    int size;   //인접행렬의 행 또는 열개수
    int** graph; //인접행렬
    int* dist;  //최단경로
    int* s; //방문여부
public:
    void LoadMatrix(std::string& filename);    // 인자로 받은 파일명으로 파일에 있는 가중치 행렬을 
                                               // 읽어서 멤버 변수로 저장
    void PrintMatrix();  // 인접 행렬을 출력
};
#include<iostream>
using namespace std;
class Graph
{
private:
    int size;   //��������� �� �Ǵ� ������
    int** graph; //�������
    int* dist;  //�ִܰ��
    int* s; //�湮����
public:
    void LoadMatrix(std::string& filename);    // ���ڷ� ���� ���ϸ����� ���Ͽ� �ִ� ����ġ ����� 
                                               // �о ��� ������ ����
    void PrintMatrix();  // ���� ����� ���
    int GetSize();       // ����� ũ��(SIZE) ��ȯ 
    void PrintShortestPathWeight(int s);     // ���� ���� s�κ��� ������ vertex������ �ִ� ����� ����ġ �� ���
};
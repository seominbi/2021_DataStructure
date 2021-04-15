#include <iostream>
using namespace std;
void Hanoi(int n, char from, char by, char to);
int main()
{
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}
void Hanoi(int n, char from, char by, char to)//���ݼ���, �����ž,���İ���ž,������ž
{
	if (n == 1) {
		cout << from << "=>" << to << endl;
	}
	else {
		Hanoi(n - 1, from , to, by);
		cout << from << "=>" << to << endl;
		Hanoi(n - 1, by, from, to);
	}
}
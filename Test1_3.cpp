#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int codeCheckNum;
int searchNum(int* array, const int m, const int first, const int last);
int main()
{
	int n;
	cin >> n; //array size

	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	int m; //search num
	cin >> m;

	cout<<searchNum(array,m,0,n-1)<<endl;
	cout << codeCheckNum<<endl;

	delete[]array;

	return 0;
}
int searchNum(int *array, const int m, const int first, const int last)
{
	if (first <= last) {
		int mid = (first + last) / 2;
		++codeCheckNum;
		if (m < array[mid]) {
			return searchNum(array, m, first, mid - 1);
		}
		else if (m > array[mid]) {
			return searchNum(array, m, mid + 1, last);
		}
		else {
			return mid;
		}
	}
	else {
		return -1;
	}
}
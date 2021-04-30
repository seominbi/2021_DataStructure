#include <iostream>
#pragma warning (disable:4996)
using namespace std;
void makeString(char* array, const int k, const int m);
int main()
{
	int n;
	cin >> n;
	char* array = new char[n];

	for (int i = 0; i < n; i++) {
		array[i] = 'a';
	}

	makeString(array,0,n-1);

	delete[]array;
	return 0;
}
void makeString(char* array, const int k, const int m)
{
	if (k == m) {
		for (int i = 0; i <= m; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = k; i <= m; i++) {
			swap(array[k], array[i]);
			makeString(array, k + 1, m);
			swap(array[k], array[i]);
		}
	}
}
void swap(char& k, char& i)
{
	char temp = k;
	k = i;
	i = temp;
}
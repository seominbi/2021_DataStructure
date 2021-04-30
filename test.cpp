#include <iostream>
#pragma warning (disable:4996)
using namespace std;
void permu(char* a, int k, int m);
void swap(char& k, char& i);
int main()
{
	int n;
	cin >> n;
	char* array;

	if (n <= 3) {
		array = new char[n];
		array[0] = { 'a' };
		array[1] = { 'b' };
	}
	else {
		array = new char[n];
		for (int i = 0; i < n/2+n%2; i++) {
			array[i]='a'
		}

	}

	return 0;
}
void swap(char& k, char& i)
{
	char temp = k;
	k = i;
	i = temp;
}
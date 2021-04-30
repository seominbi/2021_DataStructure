#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int Combination(int n, int r);
int main()
{
	int n, r;
	cin >> n >> r;
	cout << Combination(n, r);

	return 0;
}
int Combination(int n, int r)
{
	if (r == 0) { return 1; }
	else if (n == r) { return 1; }
	else if (r == 1) { return n; }
	else {
		return Combination(n - 1, r - 1) + Combination(n - 1, r);
	}
}
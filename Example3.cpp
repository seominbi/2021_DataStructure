#include <iostream>
using namespace std;
int Fibo(int n);
int main()
{
	cout << Fibo(2) << endl;
}
int Fibo(int n)
{
	if (n <= 1) {
		return n;
	}
	else {
		return Fibo(n - 1) + Fibo(n - 2);
	}
}
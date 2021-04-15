#include <iostream>
using namespace std;
int GCD(int a, int b);
int main(void)
{
	cout<<GCD(78696, 19332);
}
int GCD(int a, int b) //최대공약수
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return GCD(b, r);
	}
}
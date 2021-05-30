#include <iostream>
using namespace std;
void permutations(char *array, string prefix, int n, int k);
int main(void)
{
    char array[2] = {'a', 'b'};
    int n;
    cin>>n;
    permutations(array,"",2, n);
     
}
void permutations(char *array, string prefix, int n, int k)
{
    if (k == 0)
    {
        cout << prefix << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + array[i];
        permutations(array, newPrefix, n, k - 1);
    }
 
}
//https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
//위 사이트를 참고하였습니다.

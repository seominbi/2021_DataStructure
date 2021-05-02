#include <iostream>
using namespace std;
void printAllKLengthRec(char *set, string prefix, int n, int k);
int main(void)
{
    char array[2] = {'a', 'b'};
    int n;
    cin>>n;
    printAllKLengthRec(array,"",2, n);
     
}
void printAllKLengthRec(char set[], string prefix, int n, int k)
{
    if (k == 0)
    {
        cout << prefix << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + set[i];
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
 
}

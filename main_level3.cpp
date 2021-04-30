#include <iostream>
#include <string>
#include <sstream>
#include "list_level3.h"

using namespace std;

int main(void) {
    LinkedList list;
    //14 48 100 238 58 2

    string numbers;
    int number;
    getline(cin, numbers);

    istringstream is(numbers);
    while (is >> number) {
        if (number % 2)
            list.Append(number);
        else
            list.Prepend(number);
    }

    list.PrintReverse();
    cout << list.Length() << endl;

    return 0;
}
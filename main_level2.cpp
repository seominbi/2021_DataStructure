// �Ʒ��� ���� main�Լ����� �������� �ۼ��� list.h ������ include�Ͽ�
// �־��� ������ �����ϰ� �˴ϴ�.
// *** ����! �Ʒ��� ������ ������ ��� ����ó���� �� �ֽ��ϴ�. **
#include <iostream>
#include <string>
#include <sstream>
#include "list_level2.h"

using namespace std;

int main(void) {
    LinkedList list;

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

    list.Print();
    cout << list.Length() << endl;

    return 0;
}
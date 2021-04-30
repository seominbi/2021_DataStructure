#ifndef list_level3_h
#define list_level3_h
class LinkedList;
class Node
{
	friend class LinkedList;
private:
	int data;        // Node�� ����� data
	Node* next;  // ���� Node�� ���� pointer
	Node* prev; // ���� Node�� ���� pointer
};

class LinkedList
{
private:
	Node* head;      // List�� ���� ù Node�� ����Ű�� pointer
	Node* tail;         // List�� ���� ������ Node�� ����Ű�� pointer
public:
	LinkedList();
	~LinkedList();
	void Append(int data);   // List�� �������� ���ο� data�� ���� Node �߰�
	void Prepend(int data);  // List�� ó���� ���ο� data�� ���� Node �߰�
	int Length();                    // List�� �ִ� Node�� ���� return
	void Print();                    // List�� �ִ� ��� Node�� head���� ������� ��� (ex) 3���� ���� 4, 3, 5�� ����� ��� ==> "4 3 5" ���� ����ǥ �ȿ� �ִ� ������ cout���� ���
	void PrintReverse();        // List�� �ִ� ��� Node�� tail���� �������� ���
};
#endif // !list_h
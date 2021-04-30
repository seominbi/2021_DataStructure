#ifndef list_level2_h
#define list_level2_h

class LinkedList;
class Node {
	friend class LinkedList;
private:
	int data;        // Node�� ����� data
	Node* next;  // ���� Node�� ���� pointer
};
class LinkedList {
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();
	void Append(int data);   // List�� �������� ���ο� data�� ���� Node �߰�
	void Prepend(int data);  // List�� ó���� ���ο� data�� ���� Node �߰�
	int Length();                    // List�� �ִ� Node�� ���� return
	void Print();                    // List�� �ִ� ��� Node�� head���� ������� ���
};
#endif 
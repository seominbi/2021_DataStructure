#ifndef list_level1_h
#define list_level1_h

class LinkedList;
class Node {
private:
	friend class LinkedList;
	int data;	// Node�� ����� data
	Node* next;	 // ���� Node�� ���� pointer
};
class LinkedList {
private: 
	Node* head;	// List�� ���� ù Node�� ����Ű�� ������
public:
	LinkedList();
	~LinkedList();
	void Append(int data);   // List�� �������� ���ο� data�� ���� Node �߰�
	int Length();                    // List�� �ִ� Node�� ���� return
	void Print();                    // List�� �ִ� ��� Node�� head���� ������� ���
};

#endif // !list_h
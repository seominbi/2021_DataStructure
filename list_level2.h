#ifndef list_level2_h
#define list_level2_h

class LinkedList;
class Node {
	friend class LinkedList;
private:
	int data;        // Node에 저장될 data
	Node* next;  // 다음 Node에 대한 pointer
};
class LinkedList {
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();
	void Append(int data);   // List의 마지막에 새로운 data에 대한 Node 추가
	void Prepend(int data);  // List의 처음에 새로운 data에 대한 Node 추가
	int Length();                    // List에 있는 Node의 수를 return
	void Print();                    // List에 있는 모든 Node를 head부터 순서대로 출력
};
#endif 
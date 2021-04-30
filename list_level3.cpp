#include <iostream>
#include "list_level3.h"
LinkedList::LinkedList()
{
	head = 0;
	tail = 0;
}
LinkedList::~LinkedList()
{
	;
}
void LinkedList::Append(int data) //�������� ���ο� ��� �߰�
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	Node* curr = head;
	if (head) {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		newNode->prev = curr;
		curr->next = newNode;
		tail = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
	return;
}
void LinkedList::Prepend(int data) //ó���� ���ο� ��� �߰�
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	Node* curr = head;
	if (head) {
		newNode->data = data;
		newNode->next = head;
		newNode->prev = NULL;

		head->prev = newNode;
		head = newNode;
	}
	else {
		head = newNode;
		tail = newNode;
	}
	return;

}
int LinkedList::Length() //��� �� ����
{
	int nodeCheck = 0;
	Node* curr = head;
	while (curr->next != NULL) {
		++nodeCheck;
		curr = curr->next;
	}
	++nodeCheck;
	return nodeCheck;
}
void LinkedList::Print()	//��� ���
{
	Node* curr = head;
	while (curr->next != NULL) {
		std::cout << curr->data << " ";
		curr = curr->next;
	}
	std::cout << curr->data;
	std::cout << std::endl;

	return;
}
void LinkedList::PrintReverse()	//tail���� �������� ���
{
	Node* curr = tail;
	while (curr->prev != NULL) {
		std::cout << curr->data << " ";
		curr = curr->prev;
	}
	std::cout << curr->data;
	std::cout << std::endl;

	return;
}
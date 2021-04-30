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
void LinkedList::Append(int data) //마지막에 새로운 노드 추가
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
void LinkedList::Prepend(int data) //처음에 새로운 노드 추가
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
int LinkedList::Length() //노드 수 리턴
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
void LinkedList::Print()	//노드 출력
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
void LinkedList::PrintReverse()	//tail부터 역순으로 출력
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
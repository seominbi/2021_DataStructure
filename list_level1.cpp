#include <iostream>
#include "list_level1.h"
LinkedList::LinkedList()
{
	head = 0;
}
LinkedList::~LinkedList()
{
	;
}
void LinkedList::Append(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node* curr = head;
	if (head){
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	else {
		head=newNode;
	}
	return;
}
int LinkedList::Length()
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
void LinkedList::Print()
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
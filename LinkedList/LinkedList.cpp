#include <iostream>
#include "LinkedList.h" 
using namespace std;

void LinkedList::insertToHead (int Value) {

	Node *newNode = new Node(); 
	newNode->value = Value;

	newNode->next = head; 
	head = newNode;

	if (tail==NULL) 
		tail = head;

}

void LinkedList::insertToTail(int Value) {
    Node *newNode = new Node();
    newNode->value = Value;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void LinkedList::insertAfter(int existingValue, int newValue) {
    if (head == NULL) {
        return;
    }

    Node *current = head;
    while (current != NULL) {
        if (current->value == existingValue) {
            Node *newNode = new Node();
            newNode->value = newValue;
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    }
}

void LinkedList::printAll(){

	Node *tmp = head;

	while (tmp!=NULL) {
		cout << tmp->value << "->";
		tmp = tmp->next;
	}
	
	cout << endl;
}

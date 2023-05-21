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

void LinkedList::deleteFromHead() {
    if (head == NULL) {
        return;
    }
    
    Node* nodeToDelete = head;
    head = head->next;
    
    if (head == NULL) {
        tail = NULL;
    }
    
    delete nodeToDelete;
}

void LinkedList::deleteFromTail() {
    if (tail == NULL) {
        return;
    }
    
    if (head == tail) {
        delete tail;
        head = tail = NULL;
        return;
    }
    
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    
    delete tail;
    tail = current;
    tail->next = NULL;
}

void LinkedList::deleteByValue(int value) {
    if (head == NULL) {
        return;
    }
    
    if (head->value == value) {
        deleteFromHead();
        return;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->value == value) {
            Node* nodeToDelete = current->next;
            current->next = current->next->next;
            
            if (nodeToDelete == tail) {
                tail = current;
            }
            
            delete nodeToDelete;
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

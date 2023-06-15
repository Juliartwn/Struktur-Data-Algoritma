#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insertNode(int);
    Node* insertNodeRecursive(Node*, int);

    void deleteNode(int);
    Node* deleteNodeRecursive(Node*, int);

    bool searchNode(int);
    Node* searchNode(Node*, int);

    Node* findMin();
    Node* findMinRecursive(Node*);

    Node* findMax();
    Node* findMaxRecursive(Node*);

    void preOrder();
    void preOrderRecursive(Node*);

    void inOrder();
    void inOrderRecursive(Node*);

    void postOrder();
    void postOrderRecursive(Node*);
};

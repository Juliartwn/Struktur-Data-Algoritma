#include <iostream>
#include "BinaryTree.h"

using namespace std;

void BinaryTree::insertNode(int insertValue) {
    root = insertNodeRecursive(root, insertValue);
}

Node* BinaryTree::insertNodeRecursive(Node* currentRoot, int insertValue) {
    if (currentRoot == NULL) {
        Node* newNode = new Node();
        newNode->val = insertValue;
        return newNode;
    }

    if (insertValue < currentRoot->val) {
        currentRoot->left = insertNodeRecursive(currentRoot->left, insertValue);
    } else if (insertValue > currentRoot->val) {
        currentRoot->right = insertNodeRecursive(currentRoot->right, insertValue);
    }
    return currentRoot;
}

void BinaryTree::inOrder() {
	inOrderRecursive(root);
}

void BinaryTree::inOrderRecursive(Node* currentRoot) {
    if (currentRoot != NULL) {
        inOrderRecursive(currentRoot->left);
        cout << currentRoot->val << ", ";
        inOrderRecursive(currentRoot->right);
    }
}

void BinaryTree::preOrder() {
    preOrderRecursive(root);
}

void BinaryTree::preOrderRecursive(Node* currentRoot) {
    if (currentRoot != NULL) {
        cout << currentRoot->val << ", ";
        preOrderRecursive(currentRoot->left);
        preOrderRecursive(currentRoot->right);
    }
}

void BinaryTree::postOrder() {
    postOrderRecursive(root);
}

void BinaryTree::postOrderRecursive(Node* currentRoot) {
    if (currentRoot != NULL) {
        postOrderRecursive(currentRoot->left);
        postOrderRecursive(currentRoot->right);
        cout << currentRoot->val << ", ";
    }
}

void BinaryTree::deleteNode(int deleteValue) {
    root = deleteNodeRecursive(root, deleteValue);
}

Node* BinaryTree::deleteNodeRecursive(Node* currentRoot, int deleteValue) {
    if (currentRoot == NULL) {
        return NULL;
    }

    if (deleteValue < currentRoot->val) {
        currentRoot->left = deleteNodeRecursive(currentRoot->left, deleteValue);
    } else if (deleteValue > currentRoot->val) {
        currentRoot->right = deleteNodeRecursive(currentRoot->right, deleteValue);
    } else {
        if (currentRoot->left == NULL) {
            Node* temp = currentRoot->right;
            delete currentRoot;
            return temp;
        } else if (currentRoot->right == NULL) {
            Node* temp = currentRoot->left;
            delete currentRoot;
            return temp;
        } else {
            Node* minRightSubtree = findMinRecursive(currentRoot->right);
            currentRoot->val = minRightSubtree->val;
            currentRoot->right = deleteNodeRecursive(currentRoot->right, minRightSubtree->val);
        }
    }
    return currentRoot;
}

bool BinaryTree::searchNode(int searchValue) {
    return searchNode(root, searchValue) != NULL;
}

Node* BinaryTree::searchNode(Node* currentRoot, int searchValue) {
    if (currentRoot == NULL || currentRoot->val == searchValue) {
        return currentRoot;
    }

    if (searchValue < currentRoot->val) {
        return searchNode(currentRoot->left, searchValue);
    } else {
        return searchNode(currentRoot->right, searchValue);
    }
}

Node* BinaryTree::findMin() {
    return findMinRecursive(root);
}

Node* BinaryTree::findMinRecursive(Node* currentRoot) {
    if (currentRoot == NULL) {
        return NULL;
    }

    if (currentRoot->left == NULL) {
        return currentRoot;
    }

    return findMinRecursive(currentRoot->left);
}

Node* BinaryTree::findMax() {
    return findMaxRecursive(root);
}

Node* BinaryTree::findMaxRecursive(Node* currentRoot) {
    if (currentRoot == NULL) {
        return NULL;
    }

    if (currentRoot->right == NULL) {
        return currentRoot;
    }

    return findMaxRecursive(currentRoot->right);
}


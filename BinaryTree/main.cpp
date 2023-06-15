#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(int arg, char** argv) {

    BinaryTree bin;

    bin.insertNode(10);
    bin.insertNode(5);
    bin.insertNode(15);
    bin.insertNode(3);
    bin.insertNode(6);
    bin.insertNode(2);
    bin.insertNode(20);
    bin.insertNode(25);

    cout << "Inorder Traversal: ";
    bin.inOrder();
    cout << endl;

    cout << "Preorder Traversal: ";
    bin.preOrder();
    cout << endl;

    cout << "Postorder Traversal: ";
    bin.postOrder();
    cout << endl;

    return 0;
}

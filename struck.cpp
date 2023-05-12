#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {

    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    } 

    void push(int val) {
        if (top >= MAX_SIZE - 1) { 
            cout << "Stack overflow!" << endl; 
        } else {
            top++;
            arr[top] = val;
        }
    } 

    void pop() { 
        if (top <= -1) {
            cout << "Stack underflow!" << endl;
        } else {
            cout << "Elemen yang di-pop: " << arr[top] << endl; 
            top--;
        }
    } 

    void display() {
        if (top >= 0) {
            cout << "Elemen-elemen pada stack adalah: "; 
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        } else {
            cout << "Stack kosong!" << endl;
        }
    } 

    int get_top() { 
        if (top >= 0)
            return arr[top];
        else {
            cout << "Stack kosong!" << endl;
            return -1;
        }
    } 
};

int main() { 
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); 

    cout << "Elemen teratas pada stack adalah: " << s.get_top() << endl;

    s.pop();
    s.pop();
    s.display();

    cout << "Elemen teratas pada stack adalah: " << s.get_top() << endl;

    return 0;
}

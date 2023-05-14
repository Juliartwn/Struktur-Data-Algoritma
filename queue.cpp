#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {

    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue overflow!" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = val;
            cout << "Elemen yang ditambahkan: " << val << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow!" << endl; 
        } else {
            cout << "Elemen yang dihapus: " << arr[front] << endl;
            front++;
        }
    } 

    int get_front() {
        if (front == -1 || front > rear) {
            cout << "Queue kosong!" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    int get_rear() {
        if (front == -1 || front > rear) {
            cout << "Queue kosong!" << endl;
            return -1;
        } else {
            return arr[rear];
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue kosong!" << endl;
        } else {
            cout << "Elemen-elemen pada queue adalah: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Elemen depan pada queue adalah: " << q.get_front() << endl;
    cout << "Elemen belakang pada queue adalah: " << q.get_rear() << endl;

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "Elemen depan pada queue adalah: " << q.get_front() << endl;
    cout << "Elemen belakang pada queue adalah: " << q.get_rear() << endl;

    return 0;
}

#include <iostream>
using namespace std;

#define SIZE 5  

int cq[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot insert " << x << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    cq[rear] = x;
    cout << "Inserted " << x << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to delete" << endl;
        return;
    }
    cout << "Deleted: " << cq[front] << endl;

    if (front == rear) {  // only one element left
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
    } else {
        cout << "Front element: " << cq[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, val;

    while (true) {
        cout << "\n----- Circular Queue Menu -----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << (isEmpty() ? "Queue is EMPTY" : "Queue is NOT EMPTY") << endl;
                break;

            case 6:
                cout << (isFull() ? "Queue is FULL" : "Queue is NOT FULL") << endl;
                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again..." << endl;
        }
    }
}

#include <iostream>
using namespace std;


int stackArr[100];
int top = -1;

void push(int x) {
    if (top == 99) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        stackArr[++top] = x;
        cout << x << " pushed into stack.\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop.\n";
    } else {
        cout << stackArr[top--] << " popped from stack.\n";
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == 99;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 4:
            if (isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
using namespace std;

int queue[100], front = -1, rear = -1;

bool isEmpty() { return front == -1; }
bool isFull() { return rear == 100 - 1; }

void enqueue(int x)
{
    if (isFull())
    {
        cout << "Overflow";
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow";
        return;
    }
    cout << "Dequeued: " << queue[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void peek()
{
    if (isEmpty())
        cout << "Queue is Empty";
    else
        cout << "Front element: " << queue[front] << endl;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

int main()
{
    int choice, val;
    do
    {
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
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
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
}

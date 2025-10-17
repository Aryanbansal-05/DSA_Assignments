#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;

    Node(char d) {
        data = d;
        next = prev = nullptr;
    }
};

void insertEnd(Node*& head, char data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPal(Node* head) {
    if (head == nullptr)
        return true;

    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main() {
    Node* head = nullptr;
    int n;
    char ch;

    cout << " no. of char: ";
    cin >> n;

    cout << "Enter char: ";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        insertEnd(head, ch);
    }
    if (isPal(head))
        cout << "The doubly LL is a palindrome." << endl;
    else
        cout << "The doubly LL is not!." << endl;

    return 0;
}

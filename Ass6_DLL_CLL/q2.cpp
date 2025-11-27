#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayWithRepeat(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);

    cout << head->data << "\n";
}

void insertLast(Node* &head, int val) {
    Node* node = new Node();
    node->data = val;
    node->next = nullptr;

    if (!head) {
        head = node;
        node->next = head;  
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = node;
    node->next = head;
}

int main() {
    Node* head = nullptr;

    insertLast(head, 20);
    insertLast(head, 100);
    insertLast(head, 40);
    insertLast(head, 80);
    insertLast(head, 60);

    cout << "Output: ";
    displayWithRepeat(head);

    return 0;
}

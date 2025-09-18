#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;   
        current->next = prev;   
        prev = current;         
        current = next;         
    }
    return prev;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << "Original List: ";
    displayList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    displayList(head);

    return 0;
}

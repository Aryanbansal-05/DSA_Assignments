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
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int countAndDelete(Node*& head, int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 5);

    cout << "Original List: ";
    displayList(head);

    int key = 2;
    int count = countAndDelete(head, key);

    cout << "Occurrences of " << key << " deleted: " << count << endl;

    cout << "Updated List: ";
    displayList(head);

    return 0;
}

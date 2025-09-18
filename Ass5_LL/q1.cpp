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

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
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

void insertAtPosition(Node*& head, int value, int pos) {
    if (pos <= 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of range. Inserting at end.\n";
        insertAtEnd(head, value);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Value not found.\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void searchNode(Node* head, int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found in list.\n";
}

void displayList(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    do {
        cout << "---- Singly Linked List Menu ----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(head, value, pos);
                break;
            case 4:
                deleteFromBeginning(head);
                break;
            case 5:
                deleteFromEnd(head);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(head, value);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

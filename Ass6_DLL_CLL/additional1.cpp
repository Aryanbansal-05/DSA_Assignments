#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

void insertLast(Node* &head, int val) {
    Node* node = new Node(val);

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

int countNodes(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void splitCircular(Node* head, Node* &head1, Node* &head2) {
    if (!head) return;

    int n = countNodes(head);
    
    int firstListSize = (n + 1) / 2;

    Node* temp = head;
    
    for (int i = 1; i < firstListSize; i++) {
        temp = temp->next;
    }

    head1 = head;

    head2 = temp->next;

    temp->next = head1;

    Node* temp2 = head2;
    while (temp2->next != head)
        temp2 = temp2->next;

    temp2->next = head2;
}

void display(Node* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

int main() {
    Node* head = NULL;

    insertLast(head, 10);
    insertLast(head, 4);
    insertLast(head, 9);
    insertLast(head, 4);
    insertLast(head, 10);

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircular(head, head1, head2);

    cout << "First Circular List : ";
    display(head1);

    cout << "Second Circular List: ";
    display(head2);

    return 0;
}

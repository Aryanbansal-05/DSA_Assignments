#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

Node* reverseKNodes(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }
    return prev;
}

Node* reverseKGroup(Node* head, int k) {
    if (head == NULL) return head;

    Node* temp = head;
    int cnt = 0;

    while (temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    Node* newHead = reverseKNodes(head, k);

    head->next = reverseKGroup(temp, k);

    if (head->next != NULL) {
        head->next->prev = head;
    }

    return newHead;
}

void append(Node* &head, int val) {
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = n;
    n->prev = t;
}

void printList(Node* head) {
    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n";
}

void freeList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

int main() {
    Node* head1 = NULL;

    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);
    append(head1, 5);
    append(head1, 6);

    cout << "Original list for k=2: ";
    printList(head1);

    head1 = reverseKGroup(head1, 2);
    cout << "Reversed in groups of 2: ";
    printList(head1);

    freeList(head1);

    Node* head2 = NULL;

    append(head2, 1);
    append(head2, 2);
    append(head2, 3);
    append(head2, 4);
    append(head2, 5);
    append(head2, 6);

    cout << "\nOriginal list for k=4: ";
    printList(head2);

    head2 = reverseKGroup(head2, 4);
    cout << "Reversed in groups of 4: ";
    printList(head2);

    freeList(head2);

    return 0;
}

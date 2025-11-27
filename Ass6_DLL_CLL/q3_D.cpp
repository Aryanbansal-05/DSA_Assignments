#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(NULL), next(NULL) {}
};

void insertLast(DNode* &head, int val) {
    DNode* node = new DNode(val);
    if (!head) {
        head = node;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;
}

int sizeOfDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    DNode* head = NULL;

    insertLast(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertLast(head, 40);

    cout << "Size of Doubly Linked List = " << sizeOfDoubly(head) << "\n";

    return 0;
}

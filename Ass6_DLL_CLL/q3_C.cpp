#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(NULL) {}
};

void insertLast(CNode* &head, int val) {
    CNode* node = new CNode(val);
    if (!head) {
        head = node;
        node->next = head;  
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = node;
    node->next = head;
}

int sizeOfCircular(CNode* head) {
    if (!head) return 0;

    int count = 0;
    CNode* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main() {
    CNode* head = NULL;

    insertLast(head, 5);
    insertLast(head, 15);
    insertLast(head, 25);
    insertLast(head, 35);

    cout << "Size of Circular Linked List = " << sizeOfCircular(head) << "\n";

    return 0;
}

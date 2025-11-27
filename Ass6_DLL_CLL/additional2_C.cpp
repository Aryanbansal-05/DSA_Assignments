#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(NULL) {}
};

int parity(int x) {
    int c = 0;
    while (x > 0) {
        if (x & 1) c++;
        x >>= 1;
    }
    return c;
}

void insertLast(CNode* &head, int val) {
    CNode* n = new CNode(val);
    if (!head) {
        head = n;
        n->next = n;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
}

void deleteEvenParityCLL(CNode* &head) {
    if (!head) return;

    while (head && parity(head->data) % 2 == 0) {
        if (head->next == head) { // single node remove
            delete head;
            head = NULL;
            return;
        }
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        CNode* toDel = head;
        head = head->next;
        tail->next = head;
        delete toDel;
    }

    if (!head) return;

    CNode* cur = head->next;
    CNode* prev = head;

    while (cur != head) {
        if (parity(cur->data) % 2 == 0) { 
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void displayCLL(CNode* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    CNode* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << "\n";
}

int main() {
    CNode* head = NULL;

    insertLast(head, 9);
    insertLast(head, 11);
    insertLast(head, 34);
    insertLast(head, 6);
    insertLast(head, 13);
    insertLast(head, 21);

    deleteEvenParityCLL(head);

    cout << "Circular List Output: ";
    displayCLL(head);

    return 0;
}

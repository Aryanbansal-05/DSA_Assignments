#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(NULL), next(NULL) {}
};

int parity(int x) {
    int c = 0;
    while (x > 0) {
        if (x & 1) c++;
        x >>= 1;
    }
    return c;
}

void insertLast(DNode* &head, int val) {
    DNode* n = new DNode(val);
    if (!head) {
        head = n;
        return;
    }
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

// delete nodes with even parity
void deleteEvenParityDLL(DNode* &head) {
    DNode* cur = head;

    while (cur) {
        if (parity(cur->data) % 2 == 0) {      // even parity → remove

            if (cur == head) { // deleting head
                head = head->next;
                if (head) head->prev = NULL;
                DNode* tmp = cur;
                cur = cur->next;
                delete tmp;
                continue;
            }

            // middle or last
            DNode* p = cur->prev;
            DNode* n = cur->next;

            p->next = n;
            if (n) n->prev = p;

            delete cur;
            cur = n;
        }
        else {
            cur = cur->next;
        }
    }
}

void displayDLL(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    DNode* head = NULL;

    insertLast(head, 18);
    insertLast(head, 15);
    insertLast(head, 8);
    insertLast(head, 9);
    insertLast(head, 14);

    deleteEvenParityDLL(head);

    cout << "Doubly List Output: ";
    displayDLL(head);

    return 0;
}

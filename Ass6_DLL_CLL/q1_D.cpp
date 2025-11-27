#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};


void dl_displayForward(DNode* head) {
    if (!head) {
        cout << "Doubly List is empty.\n";
        return;
    }
    DNode* cur = head;
    cout << "Doubly List (forward): ";
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void dl_displayBackward(DNode* head) {
    if (!head) {
        cout << "Doubly List is empty.\n";
        return;
    }
    DNode* cur = head;
    while (cur->next) cur = cur->next; // go to tail
    cout << "Doubly List (backward): ";
    while (cur) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << "\n";
}

bool dl_search(DNode* head, int key) {
    DNode* cur = head;
    while (cur) {
        if (cur->data == key) return true;
        cur = cur->next;
    }
    return false;
}

void dl_insertFirst(DNode* &head, int val) {
    DNode* node = new DNode(val);
    node->next = head;
    if (head) head->prev = node;
    head = node;
}

void dl_insertLast(DNode* &head, int val) {
    DNode* node = new DNode(val);
    if (!head) { head = node; return; }
    DNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
}

void dl_insertAfter(DNode* head, int target, int val) {
    DNode* cur = head;
    while (cur) {
        if (cur->data == target) break;
        cur = cur->next;
    }
    if (!cur) { cout << "Value " << target << " not found.\n"; return; }
    DNode* node = new DNode(val);
    node->next = cur->next;
    node->prev = cur;
    cur->next = node;
    if (node->next) node->next->prev = node;
}

void dl_insertBefore(DNode* &head, int target, int val) {
    DNode* cur = head;
    while (cur) {
        if (cur->data == target) break;
        cur = cur->next;
    }
    if (!cur) { cout << "Value " << target << " not found.\n"; return; }
    if (cur == head) {
        dl_insertFirst(head, val);
        return;
    }
    DNode* node = new DNode(val);
    DNode* prevNode = cur->prev;
    prevNode->next = node;
    node->prev = prevNode;
    node->next = cur;
    cur->prev = node;
}

void dl_deleteNode(DNode* &head, int key) {
    DNode* cur = head;
    while (cur) {
        if (cur->data == key) break;
        cur = cur->next;
    }
    if (!cur) { cout << "Value " << key << " not found.\n"; return; }

    if (cur == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete cur;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    DNode* p = cur->prev;
    DNode* n = cur->next;
    p->next = n;
    if (n) n->prev = p;
    delete cur;
    cout << "Deleted node " << key << ".\n";
}

void dl_clear(DNode* &head) {
    DNode* cur = head;
    while (cur) {
        DNode* nx = cur->next;
        delete cur;
        cur = nx;
    }
    head = nullptr;
}

void doublyMenu() {
    DNode* head = nullptr;
    int choice;
    while (true) {
        cout << "\n--- Doubly List Menu ---\n";
        cout << "1. Display Forward\n2. Display Backward\n3. Insert First\n4. Insert Last\n5. Insert After value\n6. Insert Before value\n7. Delete value\n8. Search value\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) dl_displayForward(head);
        else if (choice == 2) dl_displayBackward(head);
        else if (choice == 3) {
            int v; cout << "Value to insert at first: "; cin >> v;
            dl_insertFirst(head, v);
            cout << "Inserted " << v << " at first.\n";
        } else if (choice == 4) {
            int v; cout << "Value to insert at last: "; cin >> v;
            dl_insertLast(head, v);
            cout << "Inserted " << v << " at last.\n";
        } else if (choice == 5) {
            int t, v; cout << "Insert after which value? "; cin >> t;
            cout << "Value to insert: "; cin >> v;
            dl_insertAfter(head, t, v);
        } else if (choice == 6) {
            int t, v; cout << "Insert before which value? "; cin >> t;
            cout << "Value to insert: "; cin >> v;
            dl_insertBefore(head, t, v);
        } else if (choice == 7) {
            int k; cout << "Enter value to delete: "; cin >> k;
            dl_deleteNode(head, k);
        } else if (choice == 8) {
            int k; cout << "Enter value to search: "; cin >> k;
            bool f = dl_search(head, k);
            if (f) cout << "Value " << k << " found.\n"; else cout << "Value " << k << " NOT found.\n";
        } else if (choice == 9) {
            cout << "Exiting Doubly List Menu.\n";
            dl_clear(head);
            break;
        } else cout << "Invalid choice. Try again.\n";
    }
}

int main() {
    cout << "Doubly Linked List (no class)\n";
    doublyMenu();
    return 0;
}

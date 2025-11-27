#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(nullptr) {}
};


void cl_display(CNode* head) {
    if (!head) {
        cout << "Circular List is empty.\n";
        return;
    }
    CNode* cur = head;
    cout << "Circular List: ";
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    cout << "\n";
}

bool cl_search(CNode* head, int key) {
    if (!head) return false;
    CNode* cur = head;
    do {
        if (cur->data == key) return true;
        cur = cur->next;
    } while (cur != head);
    return false;
}

void cl_insertFirst(CNode* &head, int val) {
    CNode* node = new CNode(val);
    if (!head) {
        head = node;
        node->next = node;
        return;
    }
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    node->next = head;
    tail->next = node;
    head = node;
}

void cl_insertLast(CNode* &head, int val) {
    CNode* node = new CNode(val);
    if (!head) {
        head = node;
        node->next = node;
        return;
    }
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = node;
    node->next = head;
}

void cl_insertAfter(CNode* head, int target, int val) {
    if (!head) {
        cout << "List empty. Cannot insert after " << target << ".\n";
        return;
    }
    CNode* cur = head;
    bool found = false;
    do {
        if (cur->data == target) { found = true; break; }
        cur = cur->next;
    } while (cur != head);

    if (!found) { cout << "Value " << target << " not found.\n"; return; }

    CNode* node = new CNode(val);
    node->next = cur->next;
    cur->next = node;
}

void cl_insertBefore(CNode* &head, int target, int val) {
    if (!head) {
        cout << "List empty. Cannot insert before " << target << ".\n";
        return;
    }
    if (head->data == target) {
        cl_insertFirst(head, val);
        return;
    }
    CNode* prev = head;
    CNode* cur = head->next;
    bool found = false;
    while (cur != head) {
        if (cur->data == target) { found = true; break; }
        prev = cur;
        cur = cur->next;
    }
    if (!found) { cout << "Value " << target << " not found.\n"; return; }

    CNode* node = new CNode(val);
    prev->next = node;
    node->next = cur;
}

void cl_deleteNode(CNode* &head, int key) {
    if (!head) { cout << "List empty. Nothing to delete.\n"; return; }

    // single node
    if (head->next == head) {
        if (head->data == key) {
            delete head;
            head = nullptr;
            cout << "Deleted node " << key << ". List is now empty.\n";
        } else {
            cout << "Value " << key << " not found.\n";
        }
        return;
    }

    if (head->data == key) {
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;
        CNode* toDel = head;
        head = head->next;
        tail->next = head;
        delete toDel;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    CNode* prev = head;
    CNode* cur = head->next;
    bool found = false;
    while (cur != head) {
        if (cur->data == key) { found = true; break; }
        prev = cur;
        cur = cur->next;
    }
    if (!found) { cout << "Value " << key << " not found.\n"; return; }

    prev->next = cur->next;
    delete cur;
    cout << "Deleted node " << key << ".\n";
}

void cl_clear(CNode* &head) {
    if (!head) return;
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = nullptr;

    CNode* cur = head;
    while (cur) {
        CNode* nx = cur->next;
        delete cur;
        cur = nx;
    }
    head = nullptr;
}

void circularMenu() {
    CNode* head = nullptr;
    int choice;
    while (true) {
        cout << "\n--- Circular List Menu ---\n";
        cout << "1. Display\n2. Insert First\n3. Insert Last\n4. Insert After value\n5. Insert Before value\n6. Delete value\n7. Search value\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) cl_display(head);
        else if (choice == 2) {
            int v; cout << "Value to insert at first: "; cin >> v;
            cl_insertFirst(head, v);
            cout << "Inserted " << v << " at first.\n";
        } else if (choice == 3) {
            int v; cout << "Value to insert at last: "; cin >> v;
            cl_insertLast(head, v);
            cout << "Inserted " << v << " at last.\n";
        } else if (choice == 4) {
            int t, v; cout << "Insert after which value? "; cin >> t;
            cout << "Value to insert: "; cin >> v;
            cl_insertAfter(head, t, v);
        } else if (choice == 5) {
            int t, v; cout << "Insert before which value? "; cin >> t;
            cout << "Value to insert: "; cin >> v;
            cl_insertBefore(head, t, v);
        } else if (choice == 6) {
            int k; cout << "Enter value to delete: "; cin >> k;
            cl_deleteNode(head, k);
        } else if (choice == 7) {
            int k; cout << "Enter value to search: "; cin >> k;
            bool f = cl_search(head, k);
            if (f) cout << "Value " << k << " found.\n"; else cout << "Value " << k << " NOT found.\n";
        } else if (choice == 8) {
            cout << "Exiting Circular List Menu.\n";
            cl_clear(head);
            break;
        } else cout << "Invalid choice. Try again.\n";
    }
}

int main() {
    cout << "Circular Singly Linked List (no class)\n";
    circularMenu();
    return 0;
}

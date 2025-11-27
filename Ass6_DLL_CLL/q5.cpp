
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool isCircular(Node *head) {
    if (!head) {
        return true;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    struct Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head) ? cout << "Yes" : cout << "No";

    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes" : cout << "No";

    return 0;
}
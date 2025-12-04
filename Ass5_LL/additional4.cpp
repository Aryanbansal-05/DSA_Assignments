#include <iostream>

using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
Node *rotate(Node *head, int k) {
    if (k == 0 || head == nullptr)
        return head;

    for (int i = 0; i < k; ++i) {
        Node *curr = head;
        while (curr->next != nullptr){
            curr = curr->next;
        }
           
        
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = nullptr;
    }
    return head;
}
void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if(node->next != NULL){
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
  
    head = rotate(head, 2);
    printList(head);

    return 0;
}

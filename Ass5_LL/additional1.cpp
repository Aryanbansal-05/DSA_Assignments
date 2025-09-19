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

Node* intersection(Node *A, Node *B) {
    Node* firstCurrNode = A;
	while (firstCurrNode != NULL) {
		Node* secondCurrNode = B;
		while (secondCurrNode != NULL) {
			if (firstCurrNode == secondCurrNode) {
				return secondCurrNode;
			}
			secondCurrNode = secondCurrNode->next;
		}
		firstCurrNode = firstCurrNode->next;
	}
	return NULL;
}

int main() {
    // Write C++ code here
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);
    
    
    Node* headB = new Node(6);
    headB->next = new Node(7);
    
    headB->next->next = headA->next->next;
    
    
     Node* intersectNode = intersection(headA, headB);

    if (intersectNode != NULL) {
        cout << "Intersection at node with data :" 
             << intersectNode->data << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;

    return 0;
}
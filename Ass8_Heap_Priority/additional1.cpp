#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(Node* root) {
    if (root == NULL) return 0;

    int sum = 0;

    if (isLeaf(root->left)) {
        sum += root->left->data;
    }
    else {
        sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of left leaves = " << sumOfLeftLeaves(root) << endl;

    return 0;
}

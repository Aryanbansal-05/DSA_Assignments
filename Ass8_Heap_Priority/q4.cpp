#include <iostream>
#include <climits>  
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

bool isBST(Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

bool isBSTree(Node* root) {
    return isBST(root, LLONG_MIN, LLONG_MAX);   
}

Node* newNode(int x) {
    return new Node(x);
}

int main() {

    Node* root = newNode(20);
    root->left = newNode(8);
    // root->left = newNode(50);
    root->right = newNode(30);
    root->left->left = newNode(4);
    root->left->right = newNode(12);

    if (isBSTree(root))
        cout << "The tree IS a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}

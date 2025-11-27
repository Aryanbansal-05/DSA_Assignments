#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};


Node* insertNode(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data) root->left = insertNode(root->left, key);
    else if (key > root->data) root->right = insertNode(root->right, key);
    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}


Node* searchRecursive(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur != NULL) {
        if (cur->data == key) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    Node* cur = root;
    while (cur->right != NULL) cur = cur->right;
    return cur;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    Node* cur = root;
    while (cur->left != NULL) cur = cur->left;
    return cur;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return NULL; 

    if (target->right != NULL) {
        return findMin(target->right);
    }

    Node* succ = NULL;
    Node* cur = root;
    while (cur != NULL) {
        if (key < cur->data) {
            succ = cur;      
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else {
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return NULL;

    if (target->left != NULL) {
        return findMax(target->left);
    }

    Node* pred = NULL;
    Node* cur = root;
    while (cur != NULL) {
        if (key > cur->data) {
            pred = cur;      
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else {
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;

    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(keys)/sizeof(keys[0]);
    for (int i = 0; i < n; ++i) root = insertNode(root, keys[i]);

    cout << "BST inorder: ";
    inorderPrint(root);
    cout << "\n\n";

    int s1 = 10, s2 = 15;
    Node* r1 = searchRecursive(root, s1);
    cout << "Recursive search " << s1 << ": " << (r1 ? "Found" : "Not found") << "\n";
    Node* r2 = searchIterative(root, s2);
    cout << "Iterative search " << s2 << ": " << (r2 ? "Found" : "Not found") << "\n\n";

    Node* mx = findMax(root);
    if (mx) cout << "Maximum element in BST: " << mx->data << "\n";

    Node* mn = findMin(root);
    if (mn) cout << "Minimum element in BST: " << mn->data << "\n\n";

    int q1 = 10;
    Node* succ = inorderSuccessor(root, q1);
    if (succ) cout << "Inorder successor of " << q1 << " is " << succ->data << "\n";
    else cout << "Inorder successor of " << q1 << " does not exist\n";

    q1 = 14;
    succ = inorderSuccessor(root, q1);
    if (succ) cout << "Inorder successor of " << q1 << " is " << succ->data << "\n";
    else cout << "Inorder successor of " << q1 << " does not exist\n";

    int p1 = 10;
    Node* pred = inorderPredecessor(root, p1);
    if (pred) cout << "Inorder predecessor of " << p1 << " is " << pred->data << "\n";
    else cout << "Inorder predecessor of " << p1 << " does not exist\n";

    p1 = 4;
    pred = inorderPredecessor(root, p1);
    if (pred) cout << "Inorder predecessor of " << p1 << " is " << pred->data << "\n";
    else cout << "Inorder predecessor of " << p1 << " does not exist\n";

    return 0;
}

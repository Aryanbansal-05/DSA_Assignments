#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

Node* findMinNode(Node* root) {
    if (!root) return NULL;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = findMinNode(root->right);
            root->data = succ->data;                    
            root->right = deleteNode(root->right, succ->data); 
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + ( (lh > rh) ? lh : rh );
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return 1 + ( (lh < rh) ? lh : rh );
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = NULL;

    int vals[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(vals)/sizeof(vals[0]);
    for (int i = 0; i < n; ++i) root = insertNode(root, vals[i]);

    cout << "BST inorder: ";
    inorderPrint(root);
    cout << "\n";

    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n\n";

    cout << "Deleting 10 (leaf)\n";
    root = deleteNode(root, 10);
    cout << "Inorder after delete: ";
    inorderPrint(root);
    cout << "\nMax depth: " << maxDepth(root) << ", Min depth: " << minDepth(root) << "\n\n";

    cout << "Deleting 8 (node with two children)\n";
    root = deleteNode(root, 8);
    cout << "Inorder after delete: ";
    inorderPrint(root);
    cout << "\nMax depth: " << maxDepth(root) << ", Min depth: " << minDepth(root) << "\n\n";

    cout << "Deleting 22 (node with no left child)\n";
    root = deleteNode(root, 22);
    cout << "Inorder after delete: ";
    inorderPrint(root);
    cout << "\nMax depth: " << maxDepth(root) << ", Min depth: " << minDepth(root) << "\n\n";

    freeTree(root);
    return 0;
}

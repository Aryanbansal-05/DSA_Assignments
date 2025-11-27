#include <iostream>
#include <vector>
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

Node* buildTree(vector<int>& preorder, vector<int>& inorder,
                int preStart, int preEnd,
                int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node* root = new Node(preorder[preStart]);

    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }

    int leftSize = rootIndex - inStart;

    root->left = buildTree(preorder, inorder,
                           preStart + 1, preStart + leftSize,
                           inStart, rootIndex - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1, preEnd,
                            rootIndex + 1, inEnd);

    return root;
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder traversal (" << n << " values): ";
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    cout << "Enter inorder traversal (" << n << " values): ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    Node* root = buildTree(preorder, inorder,
                           0, n - 1,
                           0, n - 1);

    cout << "\nConstructed Tree Inorder Traversal: ";
    printInorder(root);

    return 0;
}

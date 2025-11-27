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

Node* buildTree(vector<int>& inorder, vector<int>& postorder,
                int inStart, int inEnd,
                int postStart, int postEnd) 
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);

    // Find root in inorder array
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }

    int leftSize = rootIndex - inStart;

    // Build left subtree
    root->left = buildTree(inorder, postorder,
                           inStart, rootIndex - 1,
                           postStart, postStart + leftSize - 1);

    // Build right subtree
    root->right = buildTree(inorder, postorder,
                            rootIndex + 1, inEnd,
                            postStart + leftSize, postEnd - 1);

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

    vector<int> inorder(n), postorder(n);

    cout << "Enter inorder traversal (" << n << " values): ";
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    cout << "Enter postorder traversal (" << n << " values): ";
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    Node* root = buildTree(inorder, postorder,
                           0, n - 1,
                           0, n - 1);

    cout << "\nConstructed Tree Inorder Traversal: ";
    printInorder(root);

    return 0;
}

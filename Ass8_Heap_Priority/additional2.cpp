#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateRange(int l, int r) {
    vector<TreeNode*> res;
    if (l > r) {
        res.push_back(nullptr);
        return res;
    }

    for (int rootVal = l; rootVal <= r; ++rootVal) {
        vector<TreeNode*> leftTrees = generateRange(l, rootVal - 1);
        vector<TreeNode*> rightTrees = generateRange(rootVal + 1, r);

        for (TreeNode* L : leftTrees) {
            for (TreeNode* R : rightTrees) {
                TreeNode* root = new TreeNode(rootVal);
                root->left = L;
                root->right = R;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n <= 0) return {};
    return generateRange(1, n);
}

vector<string> serialize(TreeNode* root) {
    vector<string> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (cur) {
            out.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        } else {
            out.push_back("null");
        }
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    return out;
}

void printSerialized(TreeNode* root) {
    vector<string> s = serialize(root);
    cout << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        cout << s[i];
        if (i + 1 < s.size()) cout << ",";
    }
    cout << "]";
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int n = 3; 
    vector<TreeNode*> all = generateTrees(n);

    cout << "Number of unique BSTs for n = " << n << " are " << all.size() << "\n";
    cout << "Trees (level-order serialization):\n";
    for (size_t i = 0; i < all.size(); ++i) {
        printSerialized(all[i]);
        cout << "\n";
    }

    for (TreeNode* t : all) freeTree(t);
    return 0;
}

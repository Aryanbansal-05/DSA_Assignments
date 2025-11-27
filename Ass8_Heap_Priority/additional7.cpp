#include <iostream>
#include <vector>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(NULL), next(NULL) {}
};

struct BNode {
    int data;
    BNode* left;
    BNode* right;
    BNode(int v) : data(v), left(NULL), right(NULL) {}
};

BNode* bstInsert(BNode* root, int val) {
    if (root == NULL) return new BNode(val);
    if (val < root->data) root->left = bstInsert(root->left, val);
    else root->right = bstInsert(root->right, val);
    return root;
}

void inorderCollect(BNode* root, vector<int>& out) {
    if (!root) return;
    inorderCollect(root->left, out);
    out.push_back(root->data);
    inorderCollect(root->right, out);
}

vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) { res.push_back(a[i]); ++i; }
        else { res.push_back(b[j]); ++j; }
    }
    while (i < (int)a.size()) { res.push_back(a[i]); ++i; }
    while (j < (int)b.size()) { res.push_back(b[j]); ++j; }
    return res;
}

DNode* buildDLL(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    DNode* head = new DNode(vals[0]);
    DNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        DNode* node = new DNode(vals[i]);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    return head;
}

void printDLL(DNode* head) {
    DNode* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << " <-> ";
        cur = cur->next;
    }
    cout << " <-> null\n";
}

void freeTree(BNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
void freeDLL(DNode* head) {
    while (head) {
        DNode* nx = head->next;
        delete head;
        head = nx;
    }
}

int main() {

    BNode* T1 = NULL;
    T1 = bstInsert(T1, 20);
    T1 = bstInsert(T1, 10);
    T1 = bstInsert(T1, 30);
    T1 = bstInsert(T1, 25);
    T1 = bstInsert(T1, 100);
    T1 = bstInsert(T1, 50);

    BNode* T2 = NULL;
    T2 = bstInsert(T2, 50);
    T2 = bstInsert(T2, 5);
    T2 = bstInsert(T2, 70);

    vector<int> v1, v2;
    inorderCollect(T1, v1);
    inorderCollect(T2, v2);

    vector<int> merged = mergeSorted(v1, v2);

    DNode* head = buildDLL(merged);

    printDLL(head);

    freeTree(T1);
    freeTree(T2);
    freeDLL(head);

    return 0;
}

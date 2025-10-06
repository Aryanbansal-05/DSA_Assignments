#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> prevSmaller(vector<int> &A) {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < A.size(); i++) {
            while (!st.empty() && st.top() >= A[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans.push_back(st.top());
            } else {
                ans.push_back(-1);
            }

            st.push(A[i]);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {4, 5, 2, 10, 8};

    vector<int> result = s.prevSmaller(A);

    cout << "Input: ";
    for (int x : A) cout << x << " ";
    cout << endl;

    cout << "Previous Smaller Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

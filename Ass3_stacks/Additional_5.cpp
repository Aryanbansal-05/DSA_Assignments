#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canSortUsingStack(vector<int> A) {
    int n = A.size();
    
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end()); 

    stack<int> S;
    int target = 0;

    for (int i = 0; i < n; i++) {
        S.push(A[i]);

        while (!S.empty() && S.top() == sortedA[target]) {
            S.pop();
            target++;
        }
    }

    while (!S.empty() && S.top() == sortedA[target]) {
        S.pop();
        target++;
    }

    return (target == n);  
}

int main() {
    vector<int> A = {3, 1, 2};

    if (canSortUsingStack(A))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}

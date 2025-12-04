#include <iostream>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temp) {
    int n = temp.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[j] > temp[i]) {
                ans[i] = j - i;  
                break;         
            }
        }
    }

    return ans;
}

int main() {
    vector<int> temp = {100, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temp);

    cout << "Answer: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}

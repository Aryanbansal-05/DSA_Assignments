#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void sortQueue(queue<int> &q) {
    vector<int> arr;

    while (!q.empty()) {
        arr.push_back(q.front());
        q.pop();
    }

    sort(arr.begin(), arr.end());

    for (int x : arr) {
        q.push(x);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue:   ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

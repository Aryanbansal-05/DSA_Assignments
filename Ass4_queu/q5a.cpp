#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);

    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);
}

void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    q1.pop();
}

int top() {
    if (q1.empty()) return -1;
    return q1.front();
}

bool isEmpty() {
    return q1.empty();
}

int main() {
    push(10); 
    push(20); 
    push(30); 

    cout << "Top: " << top() << endl; 

    pop(); 
    cout << "Top after pop: " << top() << endl; 

    push(40); 
    cout << "Top after pushing 40: " << top() << endl;

    return 0;
}

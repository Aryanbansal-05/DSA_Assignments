#include <iostream>
#include <stack>
#include <string>
#include <cctype>  
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int applyOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  
    }
    return 0;
}

int Postfix(const string &str) {
    stack<int> st;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isdigit(c)) {
            st.push(c - '0'); 
        } else if (isOperator(c)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = applyOperation(a, b, c);
            st.push(result);
        }
    }

    return st.top();  
}

int main() {
    string postfix;
    cout << "Enter a postfix: ";
    cin >> postfix;

    int result = Postfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

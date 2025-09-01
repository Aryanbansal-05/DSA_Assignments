#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string st) {
    stack<char> s;

    for (int i = 0; i < st.length(); i++) {
        char ch = st[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;  

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string expr;
    cout << "Enter string: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "yes";
    else
        cout << "no";

    return 0;
}

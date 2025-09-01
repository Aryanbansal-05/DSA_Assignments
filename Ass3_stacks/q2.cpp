#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;   

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    return rev;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  

    string output = reverseString(input);
    cout << "Reversed string: " << output << endl;

    return 0;
}

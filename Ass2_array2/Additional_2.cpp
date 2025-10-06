#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string &s1, const string &s2) {
    return s2.find(s1) != string::npos;
}

bool canSplit(string s) {
    int n = s.size();

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplit(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

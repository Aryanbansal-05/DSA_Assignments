#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << " first string: ";
    getline(cin, str1);
    cout << " second string: ";
    getline(cin, str2);

    str1 += str2;

    cout << "Concatenated string: " << str1 << endl;
    return 0;
}

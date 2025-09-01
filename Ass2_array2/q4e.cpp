#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A'); 
    }

    cout << "Lowercase character: " << ch << endl;
    return 0;
}

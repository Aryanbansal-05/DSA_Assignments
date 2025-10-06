#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<string> genBinary(int n) {
    vector<string> result;

    for (int num = 1; num <= n; num++) {
        int temp = num;
        string b = "";

        while (temp > 0) {
            int rem = temp % 2;

            if (rem == 0)
                b += "0"; 
            else
                b += "1"; 

            temp = temp / 2;
        }
        
        reverse(b.begin(), b.end()); 
        
        result.push_back(b);
    }

    return result;
}

int main() {
    int n = 6;
    vector<string> b = genBinary(n);

    for (auto bin : b)
        cout << bin << " ";
    cout << endl;

    return 0;
}
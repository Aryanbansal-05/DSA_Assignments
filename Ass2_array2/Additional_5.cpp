#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int> &arr) {
    int n = arr.size();
    int countTwos = 0;

    for (int num : arr)
        if (num == 2)
            countTwos++;

    int i = n - 1;
    int j = n + countTwos - 1; 
    
    while (i >= 0 && j >= 0) {
        if (arr[i] == 2) {
            if (j < n)
                arr[j] = 2; 
            j--;
            if (j < n)
                arr[j] = 2;
            j--;
        } else {
            if (j < n)
                arr[j] = arr[i];
            j--;
        }
        i--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    duplicateTwos(arr);

    cout << "After duplicating 2s: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

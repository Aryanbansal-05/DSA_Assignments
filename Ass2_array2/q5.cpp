#include <iostream>
using namespace std;

void inputMatrix(int arr[10][10], int n) {
    cout << "Enter elements of tridiagonal matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j + 1 || i + 1 == j) {
                cin >> arr[i][j];
            } else {
                arr[i][j] = 0;
            }
        }
    }
}

void displayMatrix(int arr[10][10], int n) {
    cout << "Tridiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, arr[10][10];
    cout << "Enter size of square matrix: ";
    cin >> n;

    inputMatrix(arr, n);
    displayMatrix(arr, n);

    return 0;
}

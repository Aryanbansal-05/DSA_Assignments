#include <iostream>
using namespace std;

void convertToSparse(int mat[10][10], int r, int c) {
    int sparse[100][3];  
    int k = 0;           

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix Representation (Triplets):\n";
    cout << "Row Col Value\n";
    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << "   "
             << sparse[i][1] << "   "
             << sparse[i][2] << endl;
    }
}

int main() {
    int r, c, mat[10][10];
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    convertToSparse(mat, r, c);

    return 0;
}

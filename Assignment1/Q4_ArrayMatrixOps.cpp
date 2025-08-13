#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void matrixMultiplication(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return;
    }
    int res[10][10] = {0};
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) cout << res[i][j] << " ";
        cout << endl;
    }
}

void transposeMatrix(int a[10][10], int r, int c) {
    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) cout << a[j][i] << " ";
        cout << endl;
    }
}

int main() {
    // Reverse array example
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    reverseArray(arr, n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Matrix multiplication example
    int a[10][10] = {{1, 2}, {3, 4}};
    int b[10][10] = {{5, 6}, {7, 8}};
    matrixMultiplication(a, b, 2, 2, 2, 2);

    // Matrix transpose example
    transposeMatrix(a, 2, 2);

    return 0;
}

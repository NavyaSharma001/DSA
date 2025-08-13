#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    int arr[10][10];
    cout << "Enter elements: ";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += arr[i][j];
        cout << "Sum of row " << i << " = " << sum << endl;
    }

    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += arr[i][j];
        cout << "Sum of column " << j << " = " << sum << endl;
    }

    return 0;
}

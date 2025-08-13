#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        printf("%d", arr[i]);
    return 0;
}
/*
Output:
10000
Explanation: Only first element is initialized to 1, rest are 0.
*/

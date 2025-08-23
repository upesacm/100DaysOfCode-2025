#include <iostream>
using namespace std;

int xorAll(int arr[], int size) {
    int xorResult = 0;
    for (int i = 0; i < size; i++) {
        xorResult ^= arr[i];
    }
    return xorResult;
}

int main() {
    int arr[] = {4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "XOR of all elements: " << xorAll(arr, n) << endl; // Output: 7
    return 0;
}

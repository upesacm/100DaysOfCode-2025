#include <iostream>
using namespace std;

int findUnique(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i]; // XOR cancels out duplicates
    }
    return result;
}

int main() {
    int arr[] = {5, 1, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unique element: " << findUnique(arr, n) << endl; // Output: 7
    return 0;
}

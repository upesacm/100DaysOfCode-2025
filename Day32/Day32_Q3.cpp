#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 0;
    for (int i = 0; i < n; ++i) {
        x ^= arr[i];
    }
    cout << x;
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int arr[] = {5, 1, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num ^= arr[i];
    }
    cout << num;
    return 0;
}

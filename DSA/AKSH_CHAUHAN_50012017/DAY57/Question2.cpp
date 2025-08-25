#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

int main() {
    vector<int> arr = {90, 15, 10, 7, 12, 2};
    cout << (isMaxHeap(arr) ? "true" : "false") << "\n";
    return 0;
}

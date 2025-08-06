#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    
    
    if (n < k) return -1;

    
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    int max_sum = window_sum;

    
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k]; // slide forward
        max_sum = max(max_sum, window_sum); // track max
    }

    return max_sum;
}

int main() {
    vector<int> arr1 = {1, 4, 2, 10};
    vector<int> arr2 = {100, 200, 300, 400};

    cout << "Max sum (arr1): " << maxSumSubarray(arr1, 2) << endl; // Output: 12
    cout << "Max sum (arr2): " << maxSumSubarray(arr2, 2) << endl; // Output: 700

    return 0;
}

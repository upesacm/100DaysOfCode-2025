#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int> &arr, int k) {
    int maxSum = 0, windowSum = 0;

    // Calculate sum of first window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 4, 2, 10};
    int k = 2;

    cout << "Maximum sum of subarray of size " << k << " is: " << maxSumSubarray(arr, k) << endl;
    return 0;
}

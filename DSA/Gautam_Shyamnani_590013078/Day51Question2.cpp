#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubarrayWithSumGreaterThanX(const vector<int>& arr, int x) {
    int n = arr.size();
    int minLen = INT_MAX;
    int sum = 0, left = 0;

    for (int right = 0; right < n; ++right) {
        sum += arr[right];

        // Shrink the window as long as the sum is greater than x
        while (sum > x) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> arr1 = {1, 4, 45, 6, 0, 19};
    int x1 = 51;
    cout << "Output: " << smallestSubarrayWithSumGreaterThanX(arr1, x1) << endl;

    vector<int> arr2 = {1, 10, 5, 2, 7};
    int x2 = 9;
    cout << "Output: " << smallestSubarrayWithSumGreaterThanX(arr2, x2) << endl;

    return 0;
}

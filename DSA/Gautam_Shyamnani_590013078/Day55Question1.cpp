#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(const vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            int len = i - prefixSumIndex[sum - k];
            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of each prefix sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end())
            prefixSumIndex[sum] = i;
    }

    return maxLen;
}

int main() {
    vector<int> arr1 = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    cout << "Output: " << longestSubarrayWithSumK(arr1, k1) << endl;

    vector<int> arr2 = {1, 2, 3};
    int k2 = 3;
    cout << "Output: " << longestSubarrayWithSumK(arr2, k2) << endl;

    return 0;
}

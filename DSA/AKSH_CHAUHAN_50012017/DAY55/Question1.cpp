#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k) {
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == k)  // sum from start
            maxLen = i + 1;

        if (prefixIndex.find(prefixSum - k) != prefixIndex.end())
            maxLen = max(maxLen, i - prefixIndex[prefixSum - k]);

        if (prefixIndex.find(prefixSum) == prefixIndex.end())
            prefixIndex[prefixSum] = i; // store first occurrence
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << "Longest subarray length: " << longestSubarrayWithSumK(arr, k) << endl; // Output: 4
    return 0;
}

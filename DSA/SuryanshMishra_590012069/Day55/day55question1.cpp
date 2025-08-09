// 1. Longest Subarray with Sum K
// A problem that demonstrates prefix sum optimization and teaches hash-based subarray finding algorithms using cumulative sum techniques for efficient target sum detection and length maximization operations.

// Given an array and integer k, find the length of the longest subarray with sum equal to k using prefix sum and hash map approach. This operation is fundamental in subarray optimization and target sum analysis where you need to find maximum length segments meeting specific sum criteria efficiently. The technique uses prefix sum tracking with hash-based storage to detect when cumulative sums differ by exactly k, enabling O(n) time complexity. This concept is essential in financial analysis, performance tracking, and data segmentation where finding longest periods meeting target metrics enables trend analysis and performance optimization.

// This teaches prefix sum algorithms and hash-based subarray optimization techniques that are essential for target sum analysis and efficient length maximization operations.

// Your task: Implement prefix sum tracking with hash map storage to efficiently find longest subarrays meeting exact sum requirements.

// Examples
// Input:

// arr = [10, 5, 2, 7, 1, 9], k = 15
// Output:

// 4
// Input:

// arr = [1, 2, 3], k = 3
// Output:

// 2
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums, int k) {
    unordered_map<long long, int> prefixIndex;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        if (prefixIndex.find(sum - k) != prefixIndex.end()) {
            maxLen = max(maxLen, i - prefixIndex[sum - k]);
        }

        if (prefixIndex.find(sum) == prefixIndex.end()) {
            prefixIndex[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr1 = {10, 5, 2, 7, 1, 9};
    int k1 = 15;
    cout << longestSubarrayWithSumK(arr1, k1) << endl;

    vector<int> arr2 = {1, 2, 3};
    int k2 = 3;
    cout << longestSubarrayWithSumK(arr2, k2) << endl;

    return 0;
}

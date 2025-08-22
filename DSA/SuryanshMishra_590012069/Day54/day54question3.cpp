// 3. Subarrays with Product Less than K
// A problem that teaches sliding window with multiplicative constraints and demonstrates product-based counting algorithms using variable window techniques for threshold-based subarray analysis.

// Given an array and k, return the number of contiguous subarrays where the product of elements is less than k using sliding window approach. This operation is fundamental in multiplicative analysis and constraint counting where you need to count valid segments meeting product thresholds efficiently. The technique uses variable sliding window with product tracking and window contraction when exceeding limits, counting all valid subarrays ending at each position. This concept is essential in quality control, performance analysis, and threshold monitoring where counting segments meeting multiplicative criteria enables statistical analysis and process validation.

// This teaches multiplicative constraint algorithms and sliding window counting techniques that are essential for product-based analysis and efficient subarray enumeration operations.

// Your task: Implement sliding window with product constraint tracking to count all valid subarrays meeting multiplicative threshold requirements efficiently.

// Examples
// Input:

// nums = [10, 5, 2, 6], k = 100
// Output:

// 8
// Input:

// nums = [1, 2, 3], k = 0
// Output:

// 0
#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;

    int left = 0;
    long long product = 1;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << numSubarrayProductLessThanK(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << numSubarrayProductLessThanK(nums2, k2) << endl;

    return 0;
}

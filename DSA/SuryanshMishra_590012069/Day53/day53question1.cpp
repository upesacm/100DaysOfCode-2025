// 1. Max Consecutive Ones
// A problem that introduces consecutive pattern detection and teaches streak counting algorithms using single-pass traversal methods for binary data analysis and sequence processing operations.

// Given a binary array, find the maximum number of consecutive 1s in the array using efficient traversal techniques. This operation is fundamental in binary data analysis and streak detection where you need to identify longest continuous patterns within binary sequences efficiently. The technique uses single-pass traversal with streak counting to track current and maximum consecutive occurrences simultaneously. This concept is essential in signal processing, quality control, and uptime monitoring where finding longest continuous positive states enables performance analysis and reliability assessment in binary data streams.

// This teaches consecutive pattern algorithms and streak detection techniques that are essential for binary analysis and efficient sequence pattern recognition operations.

// Your task: Implement single-pass streak counting to identify maximum consecutive patterns while maintaining optimal time and space complexity.

// Examples
// Input:

// [1,1,0,1,1,1]
// Output:

// 3
// Input:

// [1,0,1,1,0,1]
// Output:

// 2
#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(const vector<int>& nums) {
    int maxCount = 0, currentCount = 0;

    for (int num : nums) {
        if (num == 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 0;
        }
    }

    return maxCount;
}

int main() {
    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums1) << endl;

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << findMaxConsecutiveOnes(nums2) << endl;

    return 0;
}

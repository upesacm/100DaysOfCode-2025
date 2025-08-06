// 2. Smallest Subarray with Sum Greater than X
// A problem that introduces minimum window optimization and teaches efficient subarray finding using sliding window techniques for threshold-based analysis and optimization problems.

// Given an array and a number x, find the smallest subarray with a sum greater than x using sliding window technique. This operation is fundamental in optimization analysis and threshold detection where you need to find minimal segments that exceed specific criteria efficiently. The technique uses variable sliding window with dynamic expansion and contraction to minimize subarray length while maintaining sum constraints. This concept is essential in resource optimization, performance analysis, and financial modeling where finding minimal resource allocations that meet targets enables efficient planning and cost optimization in array-based data systems.

// This introduces minimum window algorithms and threshold-based optimization techniques that are crucial for resource analysis and efficient minimal subarray computation operations.

// Your task: Implement dynamic sliding window with threshold tracking to find the smallest subarray exceeding target sums through efficient window management.

// Examples
// Input:

// arr = [1, 4, 45, 6, 0, 19], x = 51
// Output:

// 3
// Input:

// arr = [1, 10, 5, 2, 7], x = 9
// Output:

// 1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubarrayWithSumGreaterThanX(vector<int>& arr, int x) {
    int n = arr.size();
    int minLen = n + 1;
    int start = 0, end = 0, currSum = 0;

    while (end < n) {
        while (currSum <= x && end < n) {
            currSum += arr[end++];
        }

        while (currSum > x && start < n) {
            minLen = min(minLen, end - start);
            currSum -= arr[start++];
        }
    }

    return (minLen == n + 1) ? 0 : minLen;
}
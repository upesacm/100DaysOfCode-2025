// 3. Binary Subarray with Sum
// A problem that teaches binary array analysis and demonstrates counting algorithms using prefix sum techniques for goal-based subarray enumeration in binary data structures.

// Given a binary array and an integer goal, return the number of non-empty subarrays with sum equal to goal using prefix sum counting approach. This operation is fundamental in binary data analysis and pattern counting where you need to enumerate all segments meeting specific sum criteria efficiently. The technique uses prefix sum frequency tracking to count how many previous sums enable current position to achieve the goal sum. This concept is essential in binary signal processing, digital analysis, and statistical counting where enumerating binary patterns meeting criteria enables frequency analysis and pattern recognition in digital data streams.

// This teaches binary pattern counting algorithms and prefix sum enumeration techniques that are essential for binary analysis and efficient subarray counting operations.

// Your task: Implement prefix sum frequency counting to enumerate all binary subarrays meeting goal sum requirements through efficient pattern analysis.

// Examples
// Input:

// nums = [1,0,1,0,1], goal = 2
// Output:

// 4
// Input:

// nums = [0,0,0,0,0], goal = 0
// Output:

// 15
#include <vector>
#include <unordered_map>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;

        if (prefixCount.find(sum - goal) != prefixCount.end()) {
            count += prefixCount[sum - goal];
        }

        prefixCount[sum]++;
    }

    return count;
}

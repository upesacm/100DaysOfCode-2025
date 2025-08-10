#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // base case

    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;
        if (prefixCount.find(sum - goal) != prefixCount.end())
            count += prefixCount[sum - goal];
        prefixCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Number of binary subarrays with sum " << goal << ": " << numSubarraysWithSum(nums, goal) << endl; // Output: 4
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int numSubarraysWithSum(const vector<int>& nums, int goal) {
    unordered_map<int, int> prefixCount;
    int sum = 0, count = 0;

    prefixCount[0] = 1; // Base case: empty prefix

    for (int num : nums) {
        sum += num;

        if (prefixCount.find(sum - goal) != prefixCount.end()) {
            count += prefixCount[sum - goal];
        }

        prefixCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Output: " << numSubarraysWithSum(nums1, goal1) << endl;

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Output: " << numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}

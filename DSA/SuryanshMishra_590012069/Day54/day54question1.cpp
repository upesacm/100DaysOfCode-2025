// 1. Three Sum Problem
// A problem that introduces multi-pointer optimization techniques and teaches triplet finding algorithms using sorted array traversal methods for advanced sum-based analysis and combinatorial operations.

// Find all triplets in an array that sum up to a given target (e.g., 0) using three-pointer technique with duplicate handling. This operation is fundamental in combinatorial optimization and multi-element analysis where you need to find complex relationships between multiple array elements efficiently. The technique uses sorted array traversal with fixed first element and two-pointer search for remaining pairs, avoiding duplicate triplets through careful advancement. This concept is essential in algorithmic problem solving, financial analysis, and optimization problems where finding multi-element combinations that meet specific criteria enables complex decision making and relationship analysis.

// This teaches multi-pointer algorithms and combinatorial optimization techniques that are essential for triplet finding and efficient multi-element relationship analysis operations.

// Your task: Implement three-pointer technique with duplicate avoidance to find all unique triplets meeting target sum criteria efficiently.

// Examples
// Input:

// nums = [-1, 0, 1, 2, -1, -4]
// Output:

// [[-1, -1, 2], [-1, 0, 1]]
// Input:

// nums = [0,1,1]
// Output:

// []
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = threeSum(nums1);
    for (auto &triplet : res1) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;

    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> res2 = threeSum(nums2);
    for (auto &triplet : res2) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}

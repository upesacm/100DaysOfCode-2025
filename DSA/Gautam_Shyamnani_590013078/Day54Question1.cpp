#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // Sort the array

    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicate elements for the first pointer
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return result;
}

// Example usage
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums);

    for (const auto& triplet : triplets) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}

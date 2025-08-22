#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;  // No product can be less than 1 if all nums are positive

    int count = 0;
    int product = 1;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            ++left;
        }

        // All subarrays ending at right and starting from left to right are valid
        count += right - left + 1;
    }

    return count;
}

// Example usage
int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays with product less than " << k << ": "
         << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}

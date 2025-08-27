#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) return 0;
    int count = 0, left = 0;
    long long product = 1;

    for (int right = 0; right < nums.size(); right++) {
        product *= nums[right];

        while (product >= k && left <= right) {
            product /= nums[left];
            left++;
        }

        count += (right - left + 1); // all subarrays ending at 'right'
    }

    return count;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays: " << numSubarrayProductLessThanK(nums, k) << endl;  // Output: 8
    return 0;
}

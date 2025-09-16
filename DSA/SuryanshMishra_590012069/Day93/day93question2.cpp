#include <vector>
#include <cstddef>
#include <algorithm>
#include <limits>

using namespace std;

// Kadane's algorithm: maximum sum contiguous subarray
int maxSubArray(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int max_sum = nums[0], curr_sum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        curr_sum = max(nums[i], curr_sum + nums[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

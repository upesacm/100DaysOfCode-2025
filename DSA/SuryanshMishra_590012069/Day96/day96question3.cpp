#include <vector>
#include <numeric>
using std::vector;

// Partition Equal Subset Sum: Can array be split into two subsets with equal sum?
bool canPartition(const vector<int>& nums) {
	int total = std::accumulate(nums.begin(), nums.end(), 0);
	if (total % 2 != 0) return false;
	int target = total / 2;
	int n = nums.size();
	vector<bool> dp(target + 1, false);
	dp[0] = true;
	for (int num : nums) {
		for (int s = target; s >= num; --s) {
			dp[s] = dp[s] || dp[s - num];
		}
	}
	return dp[target];
}

#include <vector>
using std::vector;

// Subset Sum: Is there a subset with sum equal to target?
bool subsetSum(const vector<int>& nums, int target) {
	int n = nums.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
	for (int i = 0; i <= n; ++i) dp[i][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int sum = 1; sum <= target; ++sum) {
			if (nums[i - 1] <= sum)
				dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - nums[i - 1]];
			else
				dp[i][sum] = dp[i - 1][sum];
		}
	}
	return dp[n][target];
}

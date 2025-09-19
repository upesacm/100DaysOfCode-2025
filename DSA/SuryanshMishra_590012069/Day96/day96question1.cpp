#include <vector>
#include <algorithm>
using std::vector;
using std::max;

// 0/1 Knapsack: Given weights, values, and capacity W, maximize value without exceeding W
int knapsack(const vector<int>& weights, const vector<int>& values, int W) {
	int n = weights.size();
	vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int w = 0; w <= W; ++w) {
			if (weights[i - 1] <= w) {
				dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
			} else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	return dp[n][W];
}

#include <vector>
#include <climits>
using std::vector;
using std::min;

// Matrix Chain Multiplication: Minimize scalar multiplications for matrix chain
int matrixChainMultiplication(const vector<int>& dims) {
	int n = dims.size() - 1; // n matrices
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i <= n - len + 1; ++i) {
			int j = i + len - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; ++k) {
				int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}
	return dp[1][n];
}

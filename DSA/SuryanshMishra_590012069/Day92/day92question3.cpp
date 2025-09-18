#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

// Minimum cost climbing stairs (DP)
// cost: array of step costs
// Returns minimum cost to reach the top (can start at step 0 or 1)
int minCostClimbingStairs(const vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];
    vector<int> dp(n+1, 0); // dp[i]: min cost to reach step i
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    return dp[n];
}

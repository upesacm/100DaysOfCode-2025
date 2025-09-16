#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

// DP: minimum coins to make amount
int coinChange(const vector<int>& coins, int amount) {
    const int INF = amount + 1;
    vector<int> dp(amount+1, INF);
    dp[0] = 0;
    for (int a = 1; a <= amount; ++a) {
        for (int c : coins) {
            if (a - c >= 0) {
                dp[a] = min(dp[a], dp[a-c] + 1);
            }
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

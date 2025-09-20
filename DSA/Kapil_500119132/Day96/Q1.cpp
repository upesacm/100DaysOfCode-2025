#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, W;
    if (!(cin >> n >> W)) return 0;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) cin >> v[i];

    // dp[i][cap] = max value using first i items (i from 0..n)
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int cap = 0; cap <= W; ++cap) {
            if (w[i-1] <= cap)
                dp[i][cap] = max(dp[i-1][cap], v[i-1] + dp[i-1][cap - w[i-1]]);
            else
                dp[i][cap] = dp[i-1][cap];
        }
    }

    int maxValue = dp[n][W];
    cout << maxValue << '\n';

    // Reconstruct chosen items (0-based indices)
    vector<int> chosen;
    int cap = W;
    for (int i = n; i >= 1; --i) {
        if (dp[i][cap] != dp[i-1][cap]) {
            chosen.push_back(i-1);
            cap -= w[i-1];
        }
    }
    reverse(chosen.begin(), chosen.end());

    // print chosen indices and items
    cout << chosen.size();
    for (int idx : chosen) cout << " " << idx;
    cout << '\n';
    for (int idx : chosen) cout << "(" << w[idx] << "," << v[idx] << ") ";
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<char>> dp(n+1, vector<char>(target+1, 0));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1; // sum 0 achievable

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= target; ++s) {
            dp[i][s] = dp[i-1][s];
            if (!dp[i][s] && s >= a[i-1]) dp[i][s] = dp[i-1][s - a[i-1]];
        }
    }

    if (!dp[n][target]) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    // Reconstruct one subset
    vector<int> subset;
    int i = n, s = target;
    while (i > 0 && s > 0) {
        if (dp[i-1][s]) {
            i = i - 1; // not used
        } else {
            subset.push_back(i-1);
            s -= a[i-1];
            i = i - 1;
        }
    }
    reverse(subset.begin(), subset.end());
    cout << subset.size();
    for (int idx : subset) cout << " " << idx;
    cout << '\n';
    for (int idx : subset) cout << a[idx] << " ";
    cout << '\n';
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    vector<int> dp(n+1);
    dp[0] = 1; dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 4;
    cout << "Ways to climb " << n << " steps: " << climbStairs(n) << endl;
    return 0;
}

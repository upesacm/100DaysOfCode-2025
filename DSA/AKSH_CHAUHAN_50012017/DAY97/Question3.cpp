#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}

int main() {
    vector<int> dims = {1,2,3,4}; 
    cout << "Minimum multiplications: " << matrixChainMultiplication(dims) << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestPalSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence length: " << longestPalSubseq(s) << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int x : nums) total += x;

    if (total % 2 != 0) return false; 
    int target = total / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= target; s++) {
            if (nums[i-1] <= s)
                dp[i][s] = dp[i-1][s] || dp[i-1][s-nums[i-1]];
            else
                dp[i][s] = dp[i-1][s];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> arr = {1,5,11,5};
    cout << "Can partition equally? "
         << (canPartition(arr) ? "Yes" : "No") << endl;
    return 0;
}

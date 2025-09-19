#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& nums, int target) {
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
    vector<int> arr = {3,34,4,12,5,2};
    int target = 9;

    cout << "Subset sum " << target << " achievable? "
         << (subsetSum(arr, target) ? "Yes" : "No") << endl;
    return 0;
}

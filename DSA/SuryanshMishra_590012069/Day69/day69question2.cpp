#include <vector>
#include <numeric>
#include <functional>
using namespace std;
bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return false;
    }
    int target = totalSum / 2;
    int n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}
bool canPartition2D(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return false;
    }
    int target = totalSum / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
}
bool canPartitionOptimized(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return false;
    }
    int target = totalSum / 2;
    for (int num : nums) {
        if (num > target) {
            return false;
        }
    }
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
            if (dp[target]) {
                return true;
            }
        }
    }
    return dp[target];
}
pair<bool, pair<vector<int>, vector<int>>> canPartitionWithSets(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return {false, {{}, {}}};
    }
    int target = totalSum / 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    if (!dp[n][target]) {
        return {false, {{}, {}}};
    }
    vector<int> subset1, subset2;
    int i = n, j = target;
    while (i > 0 && j > 0) {
        if (!dp[i - 1][j]) {
            subset1.push_back(nums[i - 1]);
            j -= nums[i - 1];
        } else {
            subset2.push_back(nums[i - 1]);
        }
        i--;
    }
    while (i > 0) {
        subset2.push_back(nums[i - 1]);
        i--;
    }
    return {true, {subset1, subset2}};
}
bool canPartitionRecursive(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return false;
    }
    int target = totalSum / 2;
    vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
    function<bool(int, int)> helper = [&](int index, int sum) -> bool {
        if (sum == 0) return true;
        if (index >= nums.size() || sum < 0) return false;
        if (memo[index][sum] != -1) {
            return memo[index][sum];
        }
        bool result = helper(index + 1, sum - nums[index]) || helper(index + 1, sum);
        memo[index][sum] = result;
        return result;
    };
    return helper(0, target);
}
bool canPartitionBitwise(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) {
        return false;
    }
    int target = totalSum / 2;
    int n = nums.size();
    vector<bool> possible(target + 1, false);
    possible[0] = true;
    for (int num : nums) {
        for (int i = target; i >= num; i--) {
            if (possible[i - num]) {
                possible[i] = true;
            }
        }
    }
    return possible[target];
}

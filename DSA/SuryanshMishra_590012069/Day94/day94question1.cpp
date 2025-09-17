#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;

// Longest Increasing Subsequence (LIS) O(n log n) patience sorting
int lengthOfLIS(const vector<int>& nums) {
    vector<int> dp;
    for (int x : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

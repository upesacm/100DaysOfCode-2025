#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }

    sort(nums.begin(), nums.end());
    if (k % 2 == 1) nums[0] = -nums[0];

    int sum = 0;
    for (int x : nums) sum += x;
    return sum;
}

int main() {
    vector<int> nums = {3, -1, 0, 2};
    int k = 3;
    cout << "Max sum after " << k << " negations: " << largestSumAfterKNegations(nums, k) << endl;
    return 0;
}

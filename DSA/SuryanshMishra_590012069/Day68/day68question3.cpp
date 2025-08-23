#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int maxSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0;
    while (k > 0 && i < nums.size() && nums[i] < 0) {
        nums[i] = -nums[i];
        k--;
        i++;
    }
    if (k > 0 && k % 2 == 1) {
        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
    }
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return sum;
}
int maxSumAfterKNegationsHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
    }
    for (int i = 0; i < k; i++) {
        int smallest = minHeap.top();
        minHeap.pop();
        minHeap.push(-smallest);
    }
    int sum = 0;
    while (!minHeap.empty()) {
        sum += minHeap.top();
        minHeap.pop();
    }
    return sum;
}
int maxSumAfterKNegationsOptimized(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    int minAbs = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            k--;
        }
        sum += nums[i];
        minAbs = min(minAbs, abs(nums[i]));
    }
    if (k > 0 && k % 2 == 1) {
        sum -= 2 * minAbs;
    }
    return sum;
}
pair<int, vector<int>> maxSumWithOperations(vector<int>& nums, int k) {
    vector<int> result = nums;
    vector<int> operations;
    vector<int> indices(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return nums[a] < nums[b];
    });
    for (int idx : indices) {
        if (k > 0 && result[idx] < 0) {
            result[idx] = -result[idx];
            operations.push_back(idx);
            k--;
        }
    }
    if (k > 0 && k % 2 == 1) {
        int minIdx = 0;
        for (int i = 1; i < result.size(); i++) {
            if (abs(result[i]) < abs(result[minIdx])) {
                minIdx = i;
            }
        }
        result[minIdx] = -result[minIdx];
        operations.push_back(minIdx);
    }
    int sum = 0;
    for (int num : result) {
        sum += num;
    }
    return {sum, operations};
}
int maxSumSimple(vector<int>& nums, int k) {
    int negCount = 0;
    int sum = 0;
    int minAbs = INT_MAX;
    for (int num : nums) {
        if (num < 0) negCount++;
        sum += abs(num);
        minAbs = min(minAbs, abs(num));
    }
    if (k >= negCount && (k - negCount) % 2 == 1) {
        sum -= 2 * minAbs;
    }
    return sum;
}

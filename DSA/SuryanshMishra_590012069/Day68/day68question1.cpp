#include <vector>
#include <algorithm>
using namespace std;
int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    if (nums[0] == 0) return -1;
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (farthest <= i) return -1;
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= n - 1) break;
        }
    }
    return jumps;
}
int minJumpsAlternative(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    int jumps = 0;
    int currentReach = 0;
    int nextReach = 0;
    for (int i = 0; i < n - 1; i++) {
        nextReach = max(nextReach, i + nums[i]);
        if (i == currentReach) {
            jumps++;
            currentReach = nextReach;
            if (currentReach >= n - 1) break;
            if (currentReach <= i) return -1;
        }
    }
    return jumps;
}
pair<int, vector<int>> minJumpsWithPath(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return {0, {0}};
    if (nums[0] == 0) return {-1, {}};
    vector<int> parent(n, -1);
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i + nums[i] > farthest) {
            for (int j = farthest + 1; j <= min(n - 1, i + nums[i]); j++) {
                if (parent[j] == -1) parent[j] = i;
            }
            farthest = i + nums[i];
        }
        if (farthest <= i) return {-1, {}};
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= n - 1) break;
        }
    }
    vector<int> path;
    int curr = n - 1;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return {jumps, path};
}
int minJumpsBFS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    int jumps = 0;
    int start = 0, end = 0;
    while (end < n - 1) {
        jumps++;
        int farthest = end;
        for (int i = start; i <= end; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        if (farthest == end) return -1;
        start = end + 1;
        end = farthest;
    }
    return jumps;
}

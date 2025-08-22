#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int num = it->first;
        int count = it->second;
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

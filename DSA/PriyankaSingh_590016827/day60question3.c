#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> res1 = topKFrequent(arr1, k1);
    for (int n : res1) cout << n << " ";
    cout << endl;

    vector<int> arr2 = {4, 1, -1, 2, -1, 2, 3};
    int k2 = 2;
    vector<int> res2 = topKFrequent(arr2, k2);
    for (int n : res2) cout << n << " ";
    cout << endl;

    return 0;
}

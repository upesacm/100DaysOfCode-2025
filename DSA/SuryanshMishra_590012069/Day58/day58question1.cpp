#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }
    return minHeap.top();
}

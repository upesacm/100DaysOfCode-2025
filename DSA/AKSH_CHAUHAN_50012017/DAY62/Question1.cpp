#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCostToConnectRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }
    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    cout << minCostToConnectRopes(ropes) << endl; // Output: 29
    return 0;
}

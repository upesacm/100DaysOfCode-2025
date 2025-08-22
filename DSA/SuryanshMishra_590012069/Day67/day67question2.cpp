#include <vector>
#include <queue>
using namespace std;
long long minCostToConnectRopes(vector<int>& ropes) {
    if (ropes.size() <= 1) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int rope : ropes) {
        minHeap.push(rope);
    }
    long long totalCost = 0;
    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        long long cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }
    return totalCost;
}
pair<long long, vector<pair<long long, long long>>> minCostWithSequence(vector<int>& ropes) {
    if (ropes.size() <= 1) return {0, {}};
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int rope : ropes) {
        minHeap.push(rope);
    }
    long long totalCost = 0;
    vector<pair<long long, long long>> connections;
    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        connections.push_back({first, second});
        long long cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }
    return {totalCost, connections};
}
long long minCostLargeInput(vector<long long>& ropes) {
    if (ropes.size() <= 1) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (long long rope : ropes) {
        minHeap.push(rope);
    }
    long long totalCost = 0;
    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        long long cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }
    return totalCost;
}

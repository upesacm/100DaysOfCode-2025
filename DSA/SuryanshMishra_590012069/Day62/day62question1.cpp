#include <vector>
#include <queue>
using namespace std;
long long connectRopesMinCost(const vector<int>& ropes) {
	if (ropes.size() <= 1) return 0;
	priority_queue<long long, vector<long long>, greater<long long>> minHeap;
	for (int len : ropes) minHeap.push(len);
	long long total = 0;
	while (minHeap.size() > 1) {
		long long a = minHeap.top(); minHeap.pop();
		long long b = minHeap.top(); minHeap.pop();
		long long cost = a + b;
		total += cost;
		minHeap.push(cost);
	}
	return total;
}

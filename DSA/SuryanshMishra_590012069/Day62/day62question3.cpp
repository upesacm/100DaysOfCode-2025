#include <vector>
#include <queue>
using namespace std;
long long kthLargestSubarraySum(const vector<int>& arr, int k) {
	int n = (int)arr.size();
	if (k <= 0) return 0;
	vector<long long> pref(n + 1, 0);
	for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + arr[i];
	priority_queue<long long, vector<long long>, greater<long long>> minHeap;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			long long sum = pref[j + 1] - pref[i];
			if ((int)minHeap.size() < k) {
				minHeap.push(sum);
			} else if (sum > minHeap.top()) {
				minHeap.pop();
				minHeap.push(sum);
			}
		}
	}
	return minHeap.empty() ? 0 : minHeap.top();
}

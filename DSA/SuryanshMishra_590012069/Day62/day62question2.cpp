#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> kClosest(const vector<int>& arr, int target, int k) {
	if (k <= 0) return {};
	struct Node { int dist; int val; };
	auto cmp = [](const Node& a, const Node& b) {
		if (a.dist != b.dist) return a.dist < b.dist;
		return a.val < b.val;
	};
	priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
	for (int v : arr) {
		int d = std::abs(v - target);
		pq.push({d, v});
		if ((int)pq.size() > k) pq.pop();
	}
	vector<int> result;
	result.reserve(pq.size());
	while (!pq.empty()) {
		result.push_back(pq.top().val);
		pq.pop();
	}
	sort(result.begin(), result.end());
	return result;
}

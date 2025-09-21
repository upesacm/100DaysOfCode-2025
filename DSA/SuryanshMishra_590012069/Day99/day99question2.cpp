#include <vector>
#include <stack>
using std::vector;
using std::stack;

// Stack-based Maximum Window: Find max in each sliding window of size k
vector<int> maxSlidingWindowStack(const vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> res;
	stack<int> s; // stores indices
	for (int i = 0; i < n; ++i) {
		// Remove indices out of window
		while (!s.empty() && s.top() <= i - k)
			s.pop();
		// Maintain decreasing stack
		while (!s.empty() && nums[s.top()] < nums[i])
			s.pop();
		s.push(i);
		if (i >= k - 1)
			res.push_back(nums[s.top()]);
	}
	return res;
}

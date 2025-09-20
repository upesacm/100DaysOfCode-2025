#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::min;

// Palindrome Partitioning (Min Cuts): Minimize cuts for palindromic substrings
int minCut(const string& s) {
	int n = s.size();
	vector<vector<bool>> isPal(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		isPal[i][i] = true;
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			if (s[i] == s[j]) {
				if (len == 2) isPal[i][j] = true;
				else isPal[i][j] = isPal[i + 1][j - 1];
			}
		}
	}
	vector<int> cuts(n, 0);
	for (int i = 0; i < n; ++i) {
		if (isPal[0][i]) {
			cuts[i] = 0;
		} else {
			cuts[i] = i;
			for (int j = 1; j <= i; ++j) {
				if (isPal[j][i]) {
					cuts[i] = min(cuts[i], cuts[j - 1] + 1);
				}
			}
		}
	}
	return n == 0 ? 0 : cuts[n - 1];
}

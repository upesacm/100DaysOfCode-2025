#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestUniqueSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest unique substring: " << lengthOfLongestUniqueSubstring(s) << endl; // Output: 3
    return 0;
}

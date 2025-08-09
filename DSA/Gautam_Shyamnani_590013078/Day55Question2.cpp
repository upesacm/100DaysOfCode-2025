#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int longestUniqueSubstring(const string& s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); ++right) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            ++left;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string str1 = "abcabcbb";
    cout << "Output: " << longestUniqueSubstring(str1) << endl;

    string str2 = "bbbbb";
    cout << "Output: " << longestUniqueSubstring(str2) << endl;

    return 0;
}

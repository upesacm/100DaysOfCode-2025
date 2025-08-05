#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> targetFreq;
    for (char c : t) targetFreq[c]++;

    int required = targetFreq.size();
    int formed = 0;
    unordered_map<char, int> windowFreq;

    int left = 0, right = 0;
    int minLen = INT_MAX, minStart = 0;

    while (right < s.size()) {
        char c = s[right];
        windowFreq[c]++;

        if (targetFreq.count(c) && windowFreq[c] == targetFreq[c])
            formed++;

        // Try to shrink the window from the left
        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar])
                formed--;

            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}

int main() {
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Output: " << minWindow(s1, t1) << endl;

    string s2 = "a", t2 = "a";
    cout << "Output: " << minWindow(s2, t2) << endl;

    return 0;
}

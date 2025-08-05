// 3. Minimum Window Substring
// A problem that teaches advanced pattern matching techniques and demonstrates complex sliding window algorithms for multi-character substring finding using frequency-based window validation methods.

// Given two strings s and t, return the minimum window in s which contains all characters of t using advanced sliding window technique. This operation is fundamental in advanced pattern matching and substring optimization where you need to find minimal containing segments with complete character coverage. The technique uses complex sliding window with dual frequency tracking to maintain character requirements while minimizing window size. This concept is essential in bioinformatics, text search engines, and data mining where finding minimal segments containing all required elements enables efficient pattern extraction and sequence analysis in complex textual datasets.

// This teaches advanced pattern matching algorithms and multi-constraint window optimization techniques that are essential for complex substring analysis and efficient pattern containment operations.

// Your task: Implement advanced sliding window with dual frequency tracking to find minimal substrings containing all required characters efficiently.

// Examples
// Input:

// s = "ADOBECODEBANC", t = "ABC"
// Output:

// "BANC"
// Input:

// s = "a", t = "a"
// Output:

// "a"
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
    int minLen = INT_MAX;
    int minStart = 0;

    while (right < s.size()) {
        char c = s[right];
        windowFreq[c]++;

        if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
            formed++;
        }

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char lChar = s[left];
            windowFreq[lChar]--;
            if (targetFreq.count(lChar) && windowFreq[lChar] < targetFreq[lChar]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}
// 1. Longest Substring with K Unique Characters
// A problem that demonstrates advanced sliding window techniques and teaches constraint-based substring optimization using dynamic window adjustment for character diversity analysis and string processing operations.

// Given a string, find the length of the longest substring that contains exactly k unique characters using a sliding window approach. This operation is fundamental in string analysis and pattern optimization where you need to find optimal segments with specific character diversity constraints. The technique uses variable sliding window with character frequency tracking to maintain exactly k unique characters while maximizing substring length. This concept is essential in text processing, DNA sequence analysis, and data compression where finding segments with controlled character diversity enables pattern recognition and sequence optimization in biological and textual data.

// This teaches constraint-based sliding window algorithms and character diversity optimization techniques that are essential for string analysis and efficient substring pattern recognition operations.

// Your task: Implement dynamic sliding window with character frequency tracking to find the longest substring maintaining exactly k unique characters.

// Examples
// Input:

// str = "aabacbebebe", k = 3
// Output:

// 7
// Input:

// str = "aaaa", k = 2
// Output:

// 0
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestKUniqueSubstring(string s, int k) {
    int maxLen = 0;
    unordered_map<char, int> freq;
    int left = 0;

    for (int right = 0; right < s.size(); ++right) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            ++left;
        }

        if (freq.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

// 2. Longest Substring with All Distinct Characters
// A problem that introduces character uniqueness optimization and teaches sliding window techniques using hash-based duplicate detection for maximum substring length finding with distinctness constraints.

// Given a string, find the length of the longest substring without repeating characters using sliding window with character tracking. This operation is fundamental in string optimization and uniqueness analysis where you need to maximize substring length while maintaining character distinctness efficiently. The technique uses variable sliding window with hash-based character tracking to detect duplicates and contract window appropriately. This concept is essential in text processing, data validation, and pattern analysis where finding longest unique segments enables content analysis and string optimization in text-based applications.

// This introduces uniqueness constraint algorithms and character tracking techniques that are crucial for string optimization and efficient distinctness analysis operations.

// Your task: Implement sliding window with hash-based character tracking to find maximum length substrings maintaining complete character uniqueness.

// Examples
// Input:

// "abcabcbb"
// Output:

// 3
// Input:

// "bbbbb"
// Output:

// 1
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.size(); end++) {
        char c = s[end];

        if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start) {
            start = lastSeen[c] + 1;
        }

        lastSeen[c] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl;
    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl;

    return 0;
}

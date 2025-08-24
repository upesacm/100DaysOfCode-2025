#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
        while (charSet.count(s[right])) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int lengthOfLongestSubstringOptimized(string s) {
    unordered_map<char, int> charIndex;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
        if (charIndex.count(s[right]) && charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int lengthOfLongestSubstringArray(string s) {
    vector<int> charIndex(256, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
        if (charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }   
    return maxLen;
}
pair<int, string> longestSubstringWithResult(string s) {
    unordered_map<char, int> charIndex;
    int left = 0, maxLen = 0;
    int bestStart = 0, bestEnd = 0;
    for (int right = 0; right < s.length(); right++) {
        if (charIndex.count(s[right]) && charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        if (right - left + 1 > maxLen) {
            maxLen = right - left + 1;
            bestStart = left;
            bestEnd = right;
        }
    }
    string longestSubstr = s.substr(bestStart, maxLen);
    return {maxLen, longestSubstr};
}
int lengthOfLongestSubstringLowercase(string s) {
    vector<int> charIndex(26, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.length(); right++) {
        int idx = s[right] - 'a';
        if (charIndex[idx] >= left) {
            left = charIndex[idx] + 1;
        }
        charIndex[idx] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int lengthOfLongestSubstringBruteForce(string s) {
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;
        for (int j = i; j < n; j++) {
            if (seen.count(s[j])) {
                break;
            }
            seen.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
vector<string> allLongestSubstrings(string s) {
    unordered_map<char, int> charIndex;
    int left = 0, maxLen = 0;
    vector<string> results;
    for (int right = 0; right < s.length(); right++) {
        if (charIndex.count(s[right]) && charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            results.clear();
            results.push_back(s.substr(left, maxLen));
        } else if (currentLen == maxLen) {
            string current = s.substr(left, maxLen);
            if (find(results.begin(), results.end(), current) == results.end()) {
                results.push_back(current);
            }
        }
    }   
    return results;
}
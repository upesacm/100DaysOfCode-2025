#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringWithKUniqueChars(const string& s, int k) {
    if (k == 0 || s.empty()) return 0;

    unordered_map<char, int> charFreq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); ++right) {
        charFreq[s[right]]++;

        // Shrink window if unique characters exceed k
        while (charFreq.size() > k) {
            charFreq[s[left]]--;
            if (charFreq[s[left]] == 0)
                charFreq.erase(s[left]);
            left++;
        }

        // Update maxLen if window has exactly k unique characters
        if (charFreq.size() == k) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

int main() {
    string str1 = "aabacbebebe";
    int k1 = 3;
    cout << "Output: " << longestSubstringWithKUniqueChars(str1, k1) << endl;

    string str2 = "aaaa";
    int k2 = 2;
    cout << "Output: " << longestSubstringWithKUniqueChars(str2, k2) << endl;

    return 0;
}

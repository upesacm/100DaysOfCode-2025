#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringWithKUniqueChars(string s, int k) {
    unordered_map<char, int> freq;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        if (freq.size() == k)
            maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string str = "aabacbebebe";
    int k = 3;

    cout << "Longest substring length with " << k << " unique chars: "
         << longestSubstringWithKUniqueChars(str, k) << endl;
    return 0;
}

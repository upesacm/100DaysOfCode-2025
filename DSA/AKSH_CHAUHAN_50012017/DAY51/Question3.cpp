#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string minWindowSubstring(string s, string t) {
    if (t.length() > s.length()) return "";

    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0, valid = 0;
    int start = 0, minLen = INT_MAX;

    while (right < s.length()) {
        char c = s[right++];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        while (valid == need.size()) {
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }

            char d = s[left++];
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window: " << minWindowSubstring(s, t) << endl;
    return 0;
}
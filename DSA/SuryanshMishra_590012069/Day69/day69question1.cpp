#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
bool canFormPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int oddCount = 0;
    for (auto& pair : freq) {
        if (pair.second % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
bool canFormPalindromeArray(string s) {
    vector<int> freq(256, 0);
    for (char c : s) {
        freq[c]++;
    }
    int oddCount = 0;
    for (int count : freq) {
        if (count % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
pair<bool, string> canFormPalindromeWithResult(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    string left = "";
    char middle = '\0';
    bool hasMiddle = false;
    for (auto& pair : freq) {
        char ch = pair.first;
        int count = pair.second;
        for (int i = 0; i < count / 2; i++) {
            left += ch;
        }
        if (count % 2 == 1) {
            if (hasMiddle) {
                return {false, ""};
            }
            middle = ch;
            hasMiddle = true;
        }
    }
    string result = left;
    if (hasMiddle) {
        result += middle;
    }
    for (int i = left.length() - 1; i >= 0; i--) {
        result += left[i];
    }
    return {true, result};
}
bool canFormPalindromeXOR(string s) {
    unordered_map<char, bool> isOdd;
    for (char c : s) {
        isOdd[c] = !isOdd[c];
    }
    int oddCount = 0;
    for (auto& pair : isOdd) {
        if (pair.second) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
bool canFormPalindromeLowercase(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    int oddCount = 0;
    for (int count : freq) {
        if (count % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
bool canFormPalindromeBitwise(string s) {
    int bitMask = 0;
    for (char c : s) {
        bitMask ^= (1 << (c - 'a'));
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (bitMask & (1 << i)) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}
bool canFormPalindromeBitwiseOptimal(string s) {
    int bitMask = 0;
    for (char c : s) {
        bitMask ^= (1 << (c - 'a'));
    }
    return bitMask == 0 || (bitMask & (bitMask - 1)) == 0;
}
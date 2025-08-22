#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int countAnagrams(string text, string pattern) {
    int count = 0;
    int k = pattern.length();
    unordered_map<char, int> patMap, winMap;

    // Frequency map for pattern
    for (char ch : pattern) patMap[ch]++;

    int match = 0;
    for (int i = 0; i < text.length(); i++) {
        // Add current character to window map
        winMap[text[i]]++;

        // Remove character that's now outside the window
        if (i >= k) {
            if (winMap[text[i - k]] == 1)
                winMap.erase(text[i - k]);
            else
                winMap[text[i - k]]--;
        }

        // Compare maps when window size equals pattern length
        if (i >= k - 1 && winMap == patMap)
            count++;
    }

    return count;
}

int main() {
    string text1 = "forxxorfxdofr", pattern1 = "for";
    string text2 = "aabaabaa", pattern2 = "aaba";

    cout << "Anagram count (text1): " << countAnagrams(text1, pattern1) << endl; // Output: 3
    cout << "Anagram count (text2): " << countAnagrams(text2, pattern2) << endl; // Output: 4

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool compareMaps(unordered_map<char, int> &a, unordered_map<char, int> &b) {
    if (a.size() != b.size()) return false;
    for (auto &entry : a)
        if (b[entry.first] != entry.second)
            return false;
    return true;
}

int countAnagramOccurrences(string text, string pattern) {
    unordered_map<char, int> patFreq, windowFreq;
    int k = pattern.length(), count = 0;

    for (char ch : pattern)
        patFreq[ch]++;

    for (int i = 0; i < text.length(); i++) {
        windowFreq[text[i]]++;

        if (i >= k)
            windowFreq[text[i - k]]--;

        if (i >= k - 1 && compareMaps(windowFreq, patFreq))
            count++;
    }

    return count;
}

int main() {
    string text = "forxxorfxdofr", pattern = "for";
    cout << "Anagram occurrences: " << countAnagramOccurrences(text, pattern) << endl;
    return 0;
}

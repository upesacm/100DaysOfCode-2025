#include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    int oddCount = 0;
    for (auto &p : freq) {
        if (p.second % 2 != 0) oddCount++;
    }
    return oddCount <= 1;
}

int main() {
    string s;
    cin >> s;
    if (canFormPalindrome(s))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

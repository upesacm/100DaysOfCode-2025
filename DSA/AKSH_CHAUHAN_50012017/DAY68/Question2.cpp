#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

string rearrangeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<pair<int,char>> pq;
    for (auto &p : freq) pq.push({p.second, p.first});

    string result = "";
    pair<int,char> prev = {0, '#'}; // previous character

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        result += curr.second;
        curr.first--;

        if (prev.first > 0) pq.push(prev);
        prev = curr;
    }

    return (result.size() == s.size()) ? result : "";
}

int main() {
    string s = "aab";
    cout << "Rearranged string: " << rearrangeString(s) << endl;
    return 0;
}

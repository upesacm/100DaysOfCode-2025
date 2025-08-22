#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
string rearrangeCharacters(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    priority_queue<pair<int, char>> maxHeap;
    for (auto& p : freq) {
        maxHeap.push({p.second, p.first});
    }
    string result = "";
    pair<int, char> prev = {-1, '#'};
    while (!maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();
        result += curr.second;
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        curr.first--;
        prev = curr;
    }
    return result.length() == s.length() ? result : "";
}
string rearrangeCharactersAlternative(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    priority_queue<pair<int, char>> maxHeap;
    for (auto& p : freq) {
        maxHeap.push({p.second, p.first});
    }
    string result = "";
    while (maxHeap.size() >= 2) {
        auto first = maxHeap.top(); maxHeap.pop();
        auto second = maxHeap.top(); maxHeap.pop();
        result += first.second;
        result += second.second;
        first.first--;
        second.first--;
        if (first.first > 0) maxHeap.push(first);
        if (second.first > 0) maxHeap.push(second);
    }
    if (!maxHeap.empty()) {
        auto last = maxHeap.top();
        if (last.first > 1) return "";
        result += last.second;
    }
    return result;
}
string rearrangeWithDistance(string s, int k) {
    if (k <= 1) return s;
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    priority_queue<pair<int, char>> maxHeap;
    for (auto& p : freq) {
        maxHeap.push({p.second, p.first});
    }
    string result = "";
    queue<pair<int, char>> cooldown;
    while (!maxHeap.empty() || !cooldown.empty()) {
        if (!cooldown.empty() && result.length() >= k) {
            maxHeap.push(cooldown.front());
            cooldown.pop();
        }
        if (maxHeap.empty()) {
            return "";
        }
        auto curr = maxHeap.top();
        maxHeap.pop();
        result += curr.second;
        curr.first--;
        if (curr.first > 0) {
            cooldown.push(curr);
        }
    }
    return result.length() == s.length() ? result : "";
}
string rearrangeNoAdjacent(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    int maxFreq = 0;
    for (auto& p : freq) {
        maxFreq = max(maxFreq, p.second);
    }
    if (maxFreq > (s.length() + 1) / 2) {
        return "";
    }
    priority_queue<pair<int, char>> maxHeap;
    for (auto& p : freq) {
        maxHeap.push({p.second, p.first});
    }
    string result = "";
    char prevChar = '\0';
    while (!maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();
        if (curr.second == prevChar && !maxHeap.empty()) {
            auto second = maxHeap.top();
            maxHeap.pop();
            result += second.second;
            prevChar = second.second;
            second.first--;
            if (second.first > 0) maxHeap.push(second);
            maxHeap.push(curr);
        } else {
            result += curr.second;
            prevChar = curr.second;
            curr.first--;            
            if (curr.first > 0) maxHeap.push(curr);
        }
    }   
    return result;
}
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <cstddef>

using namespace std;

// Word Ladder: BFS shortest transformation sequence length
// Returns length of shortest transformation from beginWord to endWord using wordList, or 0 if impossible.
int ladderLength(const string& beginWord, const string& endWord, const vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;
    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);
    int L = beginWord.size();
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        string word = p.first;
        int depth = p.second;
        for (int i = 0; i < L; ++i) {
            string next = word;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == word[i]) continue;
                next[i] = c;
                if (dict.count(next) && !visited.count(next)) {
                    if (next == endWord) return depth + 1;
                    visited.insert(next);
                    q.push({next, depth + 1});
                }
            }
        }
    }
    return 0;
}

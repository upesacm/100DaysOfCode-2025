#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int wordLadder(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;

    queue<pair<string,int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto [word, steps] = q.front(); q.pop();

        if (word == endWord) return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dict.count(word)) {
                    dict.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main() {
    string begin = "hit", end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << "Word Ladder Length: " << wordLadder(begin, end, wordList) << endl;
    return 0;
}

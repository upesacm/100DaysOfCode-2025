#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, int> countOccurrences(queue<int> q) {
    unordered_map<int, int> freq;

    while (!q.empty()) {
        freq[q.front()]++;
        q.pop();
    }

    return freq;
}

int main() {
    queue<int> q;
    q.push(1); q.push(2); q.push(2); q.push(3); q.push(1); q.push(1);

    unordered_map<int, int> result = countOccurrences(q);

    cout << "Element Frequencies:\n";
    for (auto pair : result)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}

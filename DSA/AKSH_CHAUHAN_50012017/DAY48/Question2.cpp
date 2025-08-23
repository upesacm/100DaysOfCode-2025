#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

bool areAllUnique(queue<int> q) {
    unordered_set<int> seen;

    while (!q.empty()) {
        if (seen.count(q.front()))
            return false;
        seen.insert(q.front());
        q.pop();
    }

    return true;
}

int main() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4);

    if (areAllUnique(q))
        cout << "All elements are unique." << endl;
    else
        cout << "Duplicates found." << endl;

    return 0;
}

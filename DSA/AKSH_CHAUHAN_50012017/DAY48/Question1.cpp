#include <iostream>
#include <queue>
using namespace std;

queue<int> removeAllOccurrences(queue<int> q, int x) {
    queue<int> result;

    while (!q.empty()) {
        if (q.front() != x)
            result.push(q.front());
        q.pop();
    }

    return result;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(2); q.push(4);
    int x = 2;

    queue<int> updated = removeAllOccurrences(q, x);
    cout << "Queue after removing " << x << ": ";
    printQueue(updated);  // Output: 1 3 4

    return 0;
}

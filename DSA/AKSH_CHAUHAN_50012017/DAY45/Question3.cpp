#include <iostream>
#include <queue>
using namespace std;

int maxInQueue(queue<int> q) {
    if (q.empty()) return -1;  // Return -1 for empty queue
    int maxVal = q.front();
    q.pop();

    while (!q.empty()) {
        if (q.front() > maxVal)
            maxVal = q.front();
        q.pop();
    }
    return maxVal;
}

int main() {
    queue<int> q;
    q.push(3); q.push(5); q.push(1); q.push(2);

    cout << "Maximum element in queue: " << maxInQueue(q) << endl;  // Output: 5
    return 0;
}

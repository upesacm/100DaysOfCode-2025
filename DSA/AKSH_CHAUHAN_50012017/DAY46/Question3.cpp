#include <iostream>
#include <queue>
using namespace std;

queue<int> mergeQueues(queue<int> q1, queue<int> q2) {
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    return q1;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q1, q2;
    q1.push(1); q1.push(2);
    q2.push(3); q2.push(4);

    queue<int> merged = mergeQueues(q1, q2);
    cout << "Merged Queue: ";
    printQueue(merged);  // Output: 1 2 3 4

    return 0;
}

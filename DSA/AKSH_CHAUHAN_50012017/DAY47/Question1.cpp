#include <iostream>
#include <queue>
using namespace std;

queue<int> insertAtRear(queue<int> q, int element) {
    q.push(element);  // Standard enqueue operation
    return q;
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
    q.push(1); q.push(2);
    int element = 3;

    queue<int> result = insertAtRear(q, element);
    cout << "Queue after insertion at rear: ";
    printQueue(result);  // Output: 1 2 3

    return 0;
}
 
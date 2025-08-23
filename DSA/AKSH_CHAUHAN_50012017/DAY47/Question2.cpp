#include <iostream>
#include <queue>
using namespace std;

queue<int> insertAtFront(queue<int> q, int element) {
    queue<int> temp;
    temp.push(element);  // Insert new element at front

    // Push all old elements after it
    while (!q.empty()) {
        temp.push(q.front());
        q.pop();
    }
    return temp;
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
    q.push(2); q.push(3); q.push(4);
    int element = 1;

    queue<int> result = insertAtFront(q, element);
    cout << "Queue after insertion at front: ";
    printQueue(result);  // Output: 1 2 3 4

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

void findFrontAndRear(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    int front = q.front();
    int rear;

    while (!q.empty()) {
        rear = q.front();
        q.pop();
    }

    cout << "Front: " << front << ", Rear: " << rear << endl;
}

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30);

    findFrontAndRear(q);  // Output: Front: 10, Rear: 30

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

bool areQueuesEqual(queue<int> q1, queue<int> q2) {
    if (q1.size() != q2.size())
        return false;

    while (!q1.empty()) {
        if (q1.front() != q2.front())
            return false;
        q1.pop();
        q2.pop();
    }
    return true;
}

int main() {
    queue<int> q1, q2;
    q1.push(1); q1.push(2); q1.push(3);
    q2.push(1); q2.push(2); q2.push(3);

    if (areQueuesEqual(q1, q2))
        cout << "Queues are equal." << endl;
    else
        cout << "Queues are not equal." << endl;

    return 0;
}

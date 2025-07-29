#include <iostream>
#include <queue>
using namespace std;

bool isQueueEmpty(queue<int> q) {
    return q.empty();  // Returns true if empty, false otherwise
}

int main() {
    queue<int> q;
    
    if (isQueueEmpty(q))
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    q.push(1); q.push(2);
    
    if (isQueueEmpty(q))
        cout << "Queue is empty." << endl;
    else
        cout << "Queue is not empty." << endl;

    return 0;
}

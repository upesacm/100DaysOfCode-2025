#include <iostream>
#include <queue>
using namespace std;

int queueSize(queue<int> q) {
    return q.size();  // Direct size() method
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Size of Queue: " << queueSize(q) << endl;  // Will print: 4
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

void displayQueue(queue<int> q) {
    cout << "Queue Elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); // Note: we pass the queue by value so the original remains unchanged
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    displayQueue(q);  // Will print: 10 20 30

    return 0;
}

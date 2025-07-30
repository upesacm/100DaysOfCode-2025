#include <iostream>
#include <queue>
using namespace std;

int sumQueue(queue<int> q) {
    int sum = 0;
    while (!q.empty()) {
        sum += q.front();
        q.pop();
    }
    return sum;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Sum of queue: " << sumQueue(q) << endl;  // Output: 6
    return 0;
}

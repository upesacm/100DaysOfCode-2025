#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int findMin(queue<int> q) {
    int minVal = INT_MAX;

    while (!q.empty()) {
        if (q.front() < minVal)
            minVal = q.front();
        q.pop();
    }

    return minVal;
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(2);
    q.push(7);
    q.push(1);

    cout << "Minimum element: " << findMin(q) << endl;  // Output: 1
    return 0;
}

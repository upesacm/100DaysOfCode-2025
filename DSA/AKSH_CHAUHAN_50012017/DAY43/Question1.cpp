#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> st;

    // Step 1: Push first k elements into the stack
    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back reversed elements
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements to the back
    int size = q.size();
    for (int i = 0; i < size - k; ++i) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5);
    int k = 3;

    queue<int> res = reverseFirstK(q, k);
    cout << "Result: ";
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
    return 0;
}

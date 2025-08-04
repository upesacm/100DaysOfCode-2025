#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> s;

    
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    int size = q.size();
    for (int i = 0; i < size - k; ++i) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue<int> result = reverseFirstK(q, k);

    cout << "Resulting Queue: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    return 0;
}

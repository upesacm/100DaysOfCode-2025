#include <iostream>
#include <queue>
using namespace std;

void countEvenOdd(queue<int> q) {
    int even = 0, odd = 0;

    while (!q.empty()) {
        if (q.front() % 2 == 0)
            even++;
        else
            odd++;
        q.pop();
    }

    cout << "Even: " << even << ", Odd: " << odd << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    countEvenOdd(q);  // Output: Even: 2, Odd: 3
    return 0;
}

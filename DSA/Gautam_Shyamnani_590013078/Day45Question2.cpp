#include <iostream>
#include <queue>

using namespace std;

bool areQueuesEqual(queue<int> q1, queue<int> q2) {
    // Step 1: If sizes are different, queues can't be equal
    if (q1.size() != q2.size()) {
        return false;
    }

    // Step 2: Traverse both queues together
    while (!q1.empty()) {
        // Compare front elements
        if (q1.front() != q2.front()) {
            return false; // Mismatch found
        }

        // Move to next element in both queues
        q1.pop();
        q2.pop();
    }

    // Step 3: If we finished the loop with no mismatches, queues are equal
    return true;
}

int main() {
    // Example 1: Equal queues
    queue<int> Q1, Q2;
    Q1.push(1); Q1.push(2); Q1.push(3);
    Q2.push(1); Q2.push(2); Q2.push(3);

    if (areQueuesEqual(Q1, Q2)) {
        cout << "Yes, queues are equal." << endl;
    } else {
        cout << "No, queues are not equal." << endl;
    }

    // Example 2: Not equal queues
    queue<int> A, B;
    A.push(1); A.push(2);
    B.push(2); B.push(1);

    if (areQueuesEqual(A, B)) {
        cout << "Yes, queues are equal." << endl;
    } else {
        cout << "No, queues are not equal." << endl;
    }

    return 0;
}

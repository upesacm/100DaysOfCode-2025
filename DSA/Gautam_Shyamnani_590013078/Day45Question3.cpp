#include <iostream>
#include <queue>
#include <climits> // for INT_MIN

using namespace std;

int findMaxInQueue(queue<int> originalQueue) {
    int maxVal = INT_MIN; // Start with the lowest possible value

    // Traverse the queue using a copy
    while (!originalQueue.empty()) {
        int current = originalQueue.front(); // Get the front element

        // Update max if current is greater
        if (current > maxVal) {
            maxVal = current;
        }

        originalQueue.pop(); // Move to next element
    }

    return maxVal; // Return the highest value found
}

int main() {
    // Example 1
    queue<int> q1;
    q1.push(3);
    q1.push(5);
    q1.push(1);
    q1.push(2);

    cout << "Maximum element in queue: " << findMaxInQueue(q1) << endl;

    // Example 2
    queue<int> q2;
    q2.push(10);
    q2.push(7);
    q2.push(4);

    cout << "Maximum element in queue: " << findMaxInQueue(q2) << endl;

    return 0;
}

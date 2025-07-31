#include <iostream>
#include <queue>
#include <climits> // for INT_MAX

int findMinInQueue(std::queue<int> q) {
    int minVal = INT_MAX;

    // Traverse the queue
    while (!q.empty()) {
        int current = q.front();
        if (current < minVal) {
            minVal = current; // Update if we find a smaller value
        }
        q.pop(); // Move to next element
    }

    return minVal;
}

int main() {
    std::queue<int> myQueue;
    myQueue.push(4);
    myQueue.push(2);
    myQueue.push(7);
    myQueue.push(1);

    std::cout << "Minimum element in queue is: " << findMinInQueue(myQueue) << std::endl;

    return 0;
}

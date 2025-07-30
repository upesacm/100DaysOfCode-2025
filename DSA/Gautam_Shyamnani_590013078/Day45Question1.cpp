#include <iostream>
#include <queue>

using namespace std;

int sumQueue(queue<int> originalQueue) {
    int sum = 0;

    // Traverse through the queue without changing the original
    while (!originalQueue.empty()) {
        sum += originalQueue.front(); // Add the front element to sum
        originalQueue.pop();          // Remove the element (from copy only)
    }

    return sum; // Return the total sum
}

int main() {
    // Create a queue and add some elements
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Call the function and print the result
    int total = sumQueue(myQueue);
    cout << "Sum of queue elements: " << total << endl;

    return 0;
}

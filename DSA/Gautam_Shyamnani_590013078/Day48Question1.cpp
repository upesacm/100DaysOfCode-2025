#include <iostream>
#include <queue>
using namespace std;

// Function to remove all occurrences of x from the queue
queue<int> removeOccurrences(queue<int> q, int x) {
    queue<int> filteredQueue;

    // Traverse the original queue
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Keep only elements that are not equal to x
        if (current != x) {
            filteredQueue.push(current);
        }
    }

    return filteredQueue;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(4);

    int x = 2;

    // Remove all occurrences of x
    queue<int> result = removeOccurrences(q, x);

    // Display the updated queue
    cout << "Updated Queue: ";
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}

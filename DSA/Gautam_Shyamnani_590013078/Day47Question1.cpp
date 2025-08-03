#include <iostream>
#include <queue>
using namespace std;

// Function to insert element at the rear of the queue
queue<int> insertAtRear(queue<int> q, int value) {
    q.push(value); // Think of this as someone stepping into the line
    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);

    int newElement = 3;

    // Call the function to insert at rear
    queue<int> updatedQueue = insertAtRear(q, newElement);

    // Show the updated queue
    cout << "Queue after insertion: ";
    while (!updatedQueue.empty()) {
        cout << updatedQueue.front() << " ";
        updatedQueue.pop();
    }

    return 0;
}

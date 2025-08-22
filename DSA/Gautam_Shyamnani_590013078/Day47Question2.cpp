#include <iostream>
#include <deque>
using namespace std;

// Function to insert element at the front of the queue
deque<int> insertAtFront(deque<int> dq, int value) {
    dq.push_front(value); // Emergency! Insert at front
    return dq;
}

int main() {
    deque<int> dq = {2, 3, 4};
    int newElement = 1;

    // Insert at front
    deque<int> updatedQueue = insertAtFront(dq, newElement);

    // Display updated queue
    cout << "Queue after front insertion: ";
    for (int elem : updatedQueue) {
        cout << elem << " ";
    }

    return 0;
}

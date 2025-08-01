#include <iostream>
#include <queue>
using namespace std;

// Function to get front and rear elements without modifying the queue
void getFrontAndRear(const queue<int>& q) {
    if (q.empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    // Copy the queue to inspect it safely
    queue<int> temp = q;

    int front = temp.front();  // First person in line
    int rear;
    
    // Walk through the queue to find the last person
    while (!temp.empty()) {
        rear = temp.front();
        temp.pop();
    }

    cout << "Front: " << front << ", Rear: " << rear << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    getFrontAndRear(q);  // Should say: Front: 10, Rear: 30

    queue<int> emptyQ;
    getFrontAndRear(emptyQ);  // Should say: Queue is empty

    return 0;
}

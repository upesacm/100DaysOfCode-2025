#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;

    maxHeap.push(5);
    maxHeap.push(1);
    maxHeap.push(10);
    cout << maxHeap.top() << endl; // Output: 10

    priority_queue<int> maxHeap2;
    maxHeap2.push(3);
    maxHeap2.push(7);
    maxHeap2.push(2);
    maxHeap2.push(9);
    cout << maxHeap2.top() << ", ";
    maxHeap2.pop();
    cout << maxHeap2.top() << endl; // Output: 9, 7
}

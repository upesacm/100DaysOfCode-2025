#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> maxHeap; // stores smaller half
priority_queue<int, vector<int>, greater<int>> minHeap; // stores larger half

void addNumber(int num) {
    if (maxHeap.empty() || num <= maxHeap.top())
        maxHeap.push(num);
    else
        minHeap.push(num);

    // Balance heaps
    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double getMedian() {
    if (maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top()) / 2.0;
    return maxHeap.top();
}

int main() {
    vector<int> stream = {5, 15, 1, 3};
    for (int num : stream) {
        addNumber(num);
        cout << getMedian() << " ";
    }
    cout << endl;

    vector<int> stream2 = {1, 2, 3, 4, 5};
    maxHeap = priority_queue<int>(); // reset heaps
    minHeap = priority_queue<int, vector<int>, greater<int>>();

    for (int num : stream2) {
        addNumber(num);
        cout << getMedian() << " ";
    }
    cout << endl;

    return 0;
}

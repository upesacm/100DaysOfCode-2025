#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half

public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

int main() {
    MedianFinder mf;
    vector<int> stream1 = {5, 15, 1, 3};
    for (int num : stream1) {
        mf.addNum(num);
        cout << mf.findMedian() << " ";
    }
    cout << endl; // Output: 5 10 5 4

    MedianFinder mf2;
    vector<int> stream2 = {1, 2, 3, 4, 5};
    for (int num : stream2) {
        mf2.addNum(num);
        cout << mf2.findMedian() << " ";
    }
    cout << endl; // Output: 1 1.5 2 2.5 3
}

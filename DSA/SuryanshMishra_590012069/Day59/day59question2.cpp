#include <queue>
#include <climits>
using namespace std;
class MaxHeap {
private:
    priority_queue<int> pq;
public:
    void insert(int val) {
        pq.push(val);
    }
    int extractMax() {
        if (pq.empty()) return INT_MIN;
        int maxVal = pq.top();
        pq.pop();
        return maxVal;
    }
    int getMax() {
        return pq.empty() ? INT_MIN : pq.top();
    }
    bool isEmpty() {
        return pq.empty();
    }
    int size() {
        return pq.size();
    }
};

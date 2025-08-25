#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    for (int i = 1; i < k; i++) {
        minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << kthSmallest(arr, k) << endl; // Output: 7
    return 0;
}

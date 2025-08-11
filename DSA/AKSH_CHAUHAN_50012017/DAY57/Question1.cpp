#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargestElements(const vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse to get descending order
    sort(result.rbegin(), result.rend());
    return result;
}

int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    vector<int> result = kLargestElements(arr, k);

    cout << "[ ";
    for (int num : result) cout << num << " ";
    cout << "]\n";
    return 0;
}

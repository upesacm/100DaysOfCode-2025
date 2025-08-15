#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> kClosestNumbers(vector<int> arr, int target, int k) {
    priority_queue<pair<int, int>> maxHeap;

    for (int num : arr) {
        maxHeap.push({abs(num - target), num});
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 3, k = 2;
    vector<int> result = kClosestNumbers(arr, target, k);

    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}

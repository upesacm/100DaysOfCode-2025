#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargestSum(vector<int> arr, int k) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            int sum = prefix[end + 1] - prefix[start];
            if (minHeap.size() < k)
                minHeap.push(sum);
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> arr = {10, -10, 20, -40};
    int k = 3;
    cout << kthLargestSum(arr, k) << endl; // Output: 10
    return 0;
}

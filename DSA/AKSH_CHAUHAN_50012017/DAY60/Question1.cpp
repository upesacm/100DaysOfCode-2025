#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int index = 0;
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }

    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

int main() {
    vector<int> arr1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;
    sortKSortedArray(arr1, k1);
    for (int x : arr1) cout << x << " ";
    cout << endl; // Output: 2 3 5 6 8 9 10

    vector<int> arr2 = {3, 2, 1, 5, 4, 7, 6, 5};
    int k2 = 3;
    sortKSortedArray(arr2, k2);
    for (int x : arr2) cout << x << " ";
    cout << endl; // Output: 1 2 3 4 5 5 6 7
}

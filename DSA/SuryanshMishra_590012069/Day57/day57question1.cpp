// 1. K Largest Elements
// A problem that introduces heap-based selection algorithms and teaches efficient top-k finding techniques using priority queue data structures for optimal element retrieval and ranking operations.

// Given an array and a number k, print the k largest elements using a heap-based approach. This operation is fundamental in selection algorithms and ranking systems where you need to identify top performers or highest values efficiently without full array sorting. The technique uses min-heap of size k to maintain the k largest elements seen so far, replacing smaller elements as larger ones are encountered. This concept is essential in data analytics, recommendation systems, and performance monitoring where finding top-k elements enables efficient ranking and selection without the overhead of complete sorting operations.

// This teaches heap-based selection algorithms and priority queue optimization techniques that are essential for top-k analysis and efficient element ranking operations.

// Your task: Implement min-heap based k-largest selection to efficiently identify top elements while maintaining optimal time and space complexity.

// Examples
// Input:

// arr = [1, 23, 12, 9, 30, 2, 50], k = 3
// Output:

// [50, 30, 23]
// Input:

// arr = [10, 15, 5], k = 2
// Output:

// [15, 10]
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

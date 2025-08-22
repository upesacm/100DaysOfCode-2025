// 3. Merge K Sorted Arrays
// A problem that teaches multi-way merging techniques and demonstrates heap-based algorithm optimization for efficient sorted sequence combination using priority queue coordination methods.

// Given k sorted arrays, merge them into a single sorted array using heap-based multi-way merge algorithm. This operation is fundamental in external sorting and distributed data processing where you need to combine multiple sorted sequences efficiently while maintaining overall sorted order. The technique uses min-heap coordination to track the smallest available element from each array, ensuring optimal merging without redundant comparisons. This concept is essential in database systems, distributed computing, and large-scale data processing where merging sorted partitions enables efficient data consolidation and parallel processing optimization.

// This teaches multi-way merge algorithms and heap-based coordination techniques that are essential for sorted sequence combination and efficient distributed data processing operations.

// Your task: Implement heap-coordinated multi-way merge to efficiently combine multiple sorted arrays while maintaining optimal time complexity and sorted order.

// Examples
// Input:

// [[1, 3], [2, 4], [5, 6]]
// Output:

// [1, 2, 3, 4, 5, 6]
// Input:

// [[1, 4, 5], [1, 3, 4], [2, 6]]
// Output:

// [1, 1, 2, 3, 4, 4, 5, 6]
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const Element &other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) {
        Element curr = minHeap.top();
        minHeap.pop();

        result.push_back(curr.value);

        int nextIndex = curr.elementIndex + 1;
        if (nextIndex < arrays[curr.arrayIndex].size()) {
            minHeap.push({arrays[curr.arrayIndex][nextIndex], curr.arrayIndex, nextIndex});
        }
    }

    return result;
}
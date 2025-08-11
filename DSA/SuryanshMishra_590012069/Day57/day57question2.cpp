// 2. Is Array a Max Heap
// A problem that demonstrates heap property validation and teaches structural verification algorithms using parent-child relationship checking for data structure integrity analysis.

// Given an array, check if it satisfies the max-heap property using systematic parent-child comparison. This operation is fundamental in data structure validation and heap integrity checking where you need to verify heap properties are maintained after operations. The technique uses systematic traversal checking that each parent node is greater than or equal to its children, ensuring the complete binary tree satisfies max-heap constraints. This concept is essential in algorithm verification, data structure testing, and system validation where confirming heap properties ensures correct behavior of heap-based algorithms and maintains data structure invariants.

// This introduces heap property validation algorithms and structural verification techniques that are crucial for data structure integrity and efficient heap validation operations.

// Your task: Implement systematic parent-child validation to verify complete max-heap property compliance through efficient structural analysis.

// Examples
// Input:

// arr = [90, 15, 10, 7, 12, 2]
// Output:

// true
// Input:

// arr = [9, 15, 10, 7, 12, 2]
// Output:

// false
#include <vector>
using namespace std;

bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;

        if (right < n && arr[i] < arr[right])
            return false;
    }

    return true;
}

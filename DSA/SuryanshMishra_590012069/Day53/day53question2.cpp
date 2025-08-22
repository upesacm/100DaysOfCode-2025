// 2. Fruit Into Baskets
// A problem that demonstrates sliding window with constraint optimization and teaches two-element substring finding using variable window techniques for resource allocation and selection problems.

// You are given an array representing types of fruits. Pick two types and return the length of longest subarray with those two types using sliding window approach. This operation is fundamental in resource selection and constraint optimization where you need to maximize collection efficiency within selection limitations. The technique uses variable sliding window with type tracking to maintain exactly two fruit types while maximizing subarray length. This concept is essential in inventory management, resource allocation, and selection optimization where finding optimal segments with limited variety enables efficient resource utilization and strategic planning.

// This introduces constraint-based optimization algorithms and resource selection techniques that are crucial for allocation problems and efficient selection strategy operations.

// Your task: Implement sliding window with type constraint tracking to find maximum subarray length containing exactly two distinct elements efficiently.

// Examples
// Input:

// [1,2,1]
// Output:

// 3
// Input:

// [0,1,2,2]
// Output:

// 3
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(const vector<int>& fruits) {
    unordered_map<int, int> fruitCount;
    int left = 0, maxLen = 0;

    for (int right = 0; right < fruits.size(); ++right) {
        fruitCount[fruits[right]]++;

        while (fruitCount.size() > 2) {
            fruitCount[fruits[left]]--;
            if (fruitCount[fruits[left]] == 0) {
                fruitCount.erase(fruits[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> fruits1 = {1, 2, 1};
    cout << totalFruit(fruits1) << endl;

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << totalFruit(fruits2) << endl;

    return 0;
}

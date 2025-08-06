// 2. Find All Pairs with Given Difference
// A problem that demonstrates systematic pair enumeration and teaches difference-based searching algorithms using hash-based or two-pointer methods for comprehensive pair analysis operations.

// Given an array and a value k, find all pairs with difference k using efficient searching techniques. This operation is fundamental in difference analysis and pair enumeration where you need to identify all element relationships that meet specific difference criteria. The technique can use hash-based lookup or sorted array traversal to find all pairs efficiently while avoiding duplicate combinations. This concept is essential in statistical analysis, data comparison, and relationship mapping where finding all pairs with specific differences enables comprehensive data analysis and pattern recognition in numerical datasets.

// This introduces comprehensive pair finding algorithms and difference-based search techniques that are crucial for relationship analysis and efficient pair enumeration operations.

// Your task: Implement systematic pair finding using hash-based lookup or sorted traversal to identify all pairs meeting difference criteria comprehensively.

// Examples
// Input:

// arr = [1, 5, 3, 4, 2], k = 2
// Output:

// [(1, 3), (3, 5), (5, 3), (4, 2)]
// Input:

// arr = [8, 12, 16, 4, 0, 20], k = 4
// Output:

// [(8, 12), (12, 16), (16, 20)]
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> findPairsWithDifference(vector<int>& arr, int k) {
    unordered_set<int> seen;
    vector<pair<int, int>> result;

    for (int num : arr) {
        if (seen.count(num + k)) {
            result.push_back({num, num + k});
        }
        if (seen.count(num - k)) {
            result.push_back({num, num - k});
        }
        seen.insert(num);
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 5, 3, 4, 2};
    int k1 = 2;
    auto res1 = findPairsWithDifference(arr1, k1);
    for (auto& p : res1) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    vector<int> arr2 = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    auto res2 = findPairsWithDifference(arr2, k2);
    for (auto& p : res2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}

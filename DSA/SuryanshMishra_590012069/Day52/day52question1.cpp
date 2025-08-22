// 1. Check Array for Pair with Sum
// A problem that introduces two-pointer optimization techniques and teaches efficient pair finding algorithms using sorted array properties for target sum detection and array analysis operations.

// Given a sorted array and a number x, check if there exists a pair of elements whose sum is exactly x using two-pointer technique. This operation is fundamental in pair searching and target sum problems where you need to find complementary elements efficiently within sorted datasets. The technique uses two-pointer convergence from array ends to eliminate the need for nested loops, reducing time complexity from O(n²) to O(n). This concept is essential in algorithmic optimization, data analysis, and search problems where finding element pairs that meet specific criteria enables efficient problem solving and reduces computational overhead in large datasets.

// This teaches two-pointer algorithms and sorted array optimization techniques that are essential for pair finding and efficient target sum detection operations.

// Your task: Implement two-pointer convergence on sorted arrays to efficiently detect pairs with target sums using optimal time complexity.

// Examples
// Input:

// arr = [1, 4, 45, 6, 10, 8], x = 16
// Output:

// true
// Input:

// arr = [1, 2, 4, 3, 6], x = 10
// Output:

// false
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int x) {
    sort(arr.begin(), arr.end()); // Ensure array is sorted

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x) return true;
        else if (sum < x) left++;
        else right--;
    }

    return false;
}

int main() {
    vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int x1 = 16;
    cout << boolalpha << hasPairWithSum(arr1, x1) << endl;  // Output: true

    vector<int> arr2 = {1, 2, 4, 3, 6};
    int x2 = 10;
    cout << boolalpha << hasPairWithSum(arr2, x2) << endl;  // Output: false

    return 0;
}

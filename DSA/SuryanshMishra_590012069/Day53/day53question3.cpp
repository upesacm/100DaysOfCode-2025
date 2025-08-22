// 3. Longest Mountain in Array
// A problem that teaches geometric pattern recognition and demonstrates peak-valley detection algorithms using state-based traversal methods for topological analysis and shape recognition operations.

// Find the length of the longest mountain (increasing then decreasing) in the array using pattern recognition techniques. This operation is fundamental in topological analysis and shape recognition where you need to identify geometric patterns within numerical sequences efficiently. The technique uses state-based traversal to track increasing and decreasing phases while detecting complete mountain formations. This concept is essential in terrain analysis, stock market patterns, and signal processing where identifying peak-valley formations enables trend analysis and pattern recognition in time-series and elevation data.

// This teaches geometric pattern algorithms and state-based recognition techniques that are essential for topological analysis and efficient shape pattern detection operations.

// Your task: Implement state-based traversal to detect complete mountain patterns by tracking increasing and decreasing phases for optimal geometric recognition.

// Examples
// Input:

// [2,1,4,7,3,2,5]
// Output:

// 5
// Input:

// [2,2,2]
// Output:

// 0
#include <iostream>
#include <vector>
using namespace std;

int longestMountain(const vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    int i = 1;

    while (i < n - 1) {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            maxLen = max(maxLen, right - left + 1);
            i = right;
        } else {
            i++;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr1 = {2, 1, 4, 7, 3, 2, 5};
    cout << longestMountain(arr1) << endl;

    vector<int> arr2 = {2, 2, 2};
    cout << longestMountain(arr2) << endl;

    return 0;
}

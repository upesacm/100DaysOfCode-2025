#include <iostream>
#include <vector>
using namespace std;

void findSubarrayWithSum(const vector<int>& arr, int target) {
    int start = 0, sum = 0;

    for (int end = 0; end < arr.size(); end++) {
        sum += arr[end];  // Expand window

        // Shrink window if sum exceeds target
        while (sum > target && start < end) {
            sum -= arr[start];
            start++;
        }

        // Check if we've found the target sum
        if (sum == target) {
            cout << "Subarray found from index " << start << " to " << end << endl;
            return;
        }
    }

    cout << "No subarray with the given sum found." << endl;
}

int main() {
    vector<int> arr1 = {1, 4, 20, 3, 10, 5};
    vector<int> arr2 = {1, 4, 0, 0, 3, 10, 5};

    findSubarrayWithSum(arr1, 33); // Output: 2 to 4
    findSubarrayWithSum(arr2, 7);  // Output: 1 to 4

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void subarrayWithGivenSum(vector<int> &arr, int target) {
    int start = 0, end = 0, currSum = 0;

    while (end < arr.size()) {
        currSum += arr[end];

        while (currSum > target && start < end)
            currSum -= arr[start++];

        if (currSum == target) {
            cout << "Subarray found from index " << start << " to " << end << endl;
            return;
        }

        end++;
    }

    cout << "No subarray with given sum found." << endl;
}

int main() {
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int target = 33;

    subarrayWithGivenSum(arr, target);  // Output: index 2 to 4
    return 0;
}

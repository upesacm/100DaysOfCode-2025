#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubarrayWithSumGreaterThanX(vector<int> &arr, int x) {
    int minLen = INT_MAX, sum = 0, left = 0;

    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];

        while (sum > x) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int x = 51;

    cout << "Smallest subarray length with sum > " << x << ": "
         << smallestSubarrayWithSumGreaterThanX(arr, x) << endl;
    return 0;
}

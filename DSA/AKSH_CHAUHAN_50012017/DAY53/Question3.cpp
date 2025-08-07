#include <iostream>
#include <vector>
using namespace std;

int longestMountain(vector<int> &arr) {
    int n = arr.size(), maxLen = 0;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { // peak
            int left = i, right = i;

            while (left > 0 && arr[left] > arr[left - 1])
                left--;
            while (right < n - 1 && arr[right] > arr[right + 1])
                right++;

            maxLen = max(maxLen, right - left + 1);
            i = right;  // skip processed mountain
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    cout << "Longest mountain length: " << longestMountain(arr) << endl;  // Output: 5
    return 0;
}

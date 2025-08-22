#include <iostream>
#include <vector>
using namespace std;

int longestMountain(const vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;

    for (int i = 1; i < n - 1; ++i) {
        // Check if current element is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Move left while climbing up
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            // Move right while going down
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Calculate mountain length
            int mountainLen = right - left + 1;
            maxLen = max(maxLen, mountainLen);
        }
    }

    return maxLen;
}

int main() {
    vector<int> trail1 = {2, 1, 4, 7, 3, 2, 5};
    vector<int> trail2 = {2, 2, 2};

    cout << "Longest mountain in trail1: " << longestMountain(trail1) << endl;
    cout << "Longest mountain in trail2: " << longestMountain(trail2) << endl;

    return 0;
}

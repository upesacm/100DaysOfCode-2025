#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasPairWithSum(vector<int> &arr, int x) {
    sort(arr.begin(), arr.end()); // Ensure array is sorted
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x)
            return true;
        else if (sum < x)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int x = 16;

    cout << (hasPairWithSum(arr, x) ? "true" : "false") << endl;
    return 0;
}

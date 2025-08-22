#include <iostream>
#include <vector>
#include <algorithm> // for sort

bool hasPairWithSum(std::vector<int>& arr, int x) {
    std::sort(arr.begin(), arr.end()); // Ensure array is sorted
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == x)
            return true;
        else if (currentSum < x)
            ++left; // Need a larger sum
        else
            --right; // Need a smaller sum
    }
    return false;
}

int main() {
    std::vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int x1 = 16;
    std::cout << std::boolalpha << hasPairWithSum(arr1, x1) << std::endl; // true

    std::vector<int> arr2 = {1, 2, 4, 3, 6};
    int x2 = 10;
    std::cout << std::boolalpha << hasPairWithSum(arr2, x2) << std::endl; // false

    return 0;
}

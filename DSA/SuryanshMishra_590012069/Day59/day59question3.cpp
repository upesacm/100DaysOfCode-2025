#include <vector>
using namespace std;
bool isMaxHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) {
            return false;
        }
        if (right < n && arr[i] < arr[right]) {
            return false;
        }
    }
    return true;
}
bool isMinHeap(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] > arr[left]) {
            return false;
        }
        if (right < n && arr[i] > arr[right]) {
            return false;
        }
    }
    return true;
}
bool areHeapsIdentical(const vector<int>& arr1, const vector<int>& arr2) {
    // Check if sizes are different
    if (arr1.size() != arr2.size()) {
        return false;
    }
    if (arr1 != arr2) {
        return false;
    }
    bool isMaxHeap1 = isMaxHeap(arr1);
    bool isMinHeap1 = isMinHeap(arr1);
    bool isMaxHeap2 = isMaxHeap(arr2);
    bool isMinHeap2 = isMinHeap(arr2);
    return (isMaxHeap1 && isMaxHeap2) || (isMinHeap1 && isMinHeap2);
}

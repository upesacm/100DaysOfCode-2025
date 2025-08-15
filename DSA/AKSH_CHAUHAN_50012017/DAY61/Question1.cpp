#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 2};
    convertMinToMaxHeap(arr);

    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}

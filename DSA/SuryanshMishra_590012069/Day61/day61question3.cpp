#include <vector>
using namespace std;
static void siftDownHS(vector<int>& arr, int i, int heapSize) {
	while (true) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < heapSize && arr[left] > arr[largest]) largest = left;
		if (right < heapSize && arr[right] > arr[largest]) largest = right;
		if (largest == i) break;
		swap(arr[i], arr[largest]);
		i = largest;
	}
}
void heapSort(vector<int>& arr) {
	int n = (int)arr.size();
	if (n <= 1) return;
	for (int i = n / 2 - 1; i >= 0; --i) {
		siftDownHS(arr, i, n);
	}
	for (int end = n - 1; end > 0; --end) {
		swap(arr[0], arr[end]);
		siftDownHS(arr, 0, end);
	}
}

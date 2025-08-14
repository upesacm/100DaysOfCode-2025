#include <vector>
using namespace std;
void siftDown(vector<int>& arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest]) largest = left;
	if (right < n && arr[right] > arr[largest]) largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		siftDown(arr, n, largest);
	}
}
void replaceRoot(vector<int>& arr, int newElement) {
	if (arr.empty()) return;
	arr[0] = newElement;
	siftDown(arr, arr.size(), 0);
}
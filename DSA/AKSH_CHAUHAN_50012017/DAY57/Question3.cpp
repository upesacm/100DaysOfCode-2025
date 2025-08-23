#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value, arrayIndex, elementIndex;
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Push first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) {
        Element curr = minHeap.top();
        minHeap.pop();
        result.push_back(curr.value);

        int nextIndex = curr.elementIndex + 1;
        if (nextIndex < arrays[curr.arrayIndex].size()) {
            minHeap.push({arrays[curr.arrayIndex][nextIndex], curr.arrayIndex, nextIndex});
        }
    }
    return result;
}

int main() {
    vector<vector<int>> arrays = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<int> result = mergeKSortedArrays(arrays);

    cout << "[ ";
    for (int num : result) cout << num << " ";
    cout << "]\n";
    return 0;
}

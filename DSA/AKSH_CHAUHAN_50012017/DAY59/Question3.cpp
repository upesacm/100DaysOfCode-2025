#include <iostream>
#include <vector>
using namespace std;

bool areIdentical(const vector<int>& heap1, const vector<int>& heap2) {
    if (heap1.size() != heap2.size()) return false;
    for (size_t i = 0; i < heap1.size(); i++) {
        if (heap1[i] != heap2[i]) return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {10, 9, 8};
    vector<int> arr2 = {10, 9, 8};
    cout << (areIdentical(arr1, arr2) ? "true" : "false") << endl; // true

    vector<int> arr3 = {10, 9, 8};
    vector<int> arr4 = {10, 8, 9};
    cout << (areIdentical(arr3, arr4) ? "true" : "false") << endl; // false
}

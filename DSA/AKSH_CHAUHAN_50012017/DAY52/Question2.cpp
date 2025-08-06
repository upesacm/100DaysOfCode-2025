#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> findPairsWithDiff(vector<int> &arr, int k) {
    unordered_set<int> s(arr.begin(), arr.end());
    vector<pair<int, int>> result;

    for (int num : arr) {
        if (s.count(num + k))
            result.emplace_back(num, num + k);
        if (s.count(num - k))
            result.emplace_back(num, num - k);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;

    vector<pair<int, int>> pairs = findPairsWithDiff(arr, k);

    cout << "Pairs with difference " << k << ": ";
    for (auto p : pairs)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;

    return 0;
}

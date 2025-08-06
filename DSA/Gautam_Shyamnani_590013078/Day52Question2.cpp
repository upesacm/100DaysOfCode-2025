#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::pair<int, int>> findPairsWithDifference(const std::vector<int>& arr, int k) {
    std::unordered_set<int> elements(arr.begin(), arr.end()); // Fast lookup
    std::vector<std::pair<int, int>> result;

    for (int num : arr) {
        if (elements.count(num + k)) {
            result.push_back({num, num + k});
        }
        if (elements.count(num - k)) {
            result.push_back({num, num - k});
        }
    }

    return result;
}

int main() {
    std::vector<int> arr1 = {1, 5, 3, 4, 2};
    int k1 = 2;
    auto pairs1 = findPairsWithDifference(arr1, k1);
    std::cout << "Pairs with difference " << k1 << ":\n";
    for (auto& p : pairs1) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    std::vector<int> arr2 = {8, 12, 16, 4, 0, 20};
    int k2 = 4;
    auto pairs2 = findPairsWithDifference(arr2, k2);
    std::cout << "\nPairs with difference " << k2 << ":\n";
    for (auto& p : pairs2) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}

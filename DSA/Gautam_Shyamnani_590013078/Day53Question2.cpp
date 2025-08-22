#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(const vector<int>& fruits) {
    unordered_map<int, int> basket;  // Tracks count of each fruit type
    int left = 0, maxLen = 0;

    for (int right = 0; right < fruits.size(); ++right) {
        basket[fruits[right]]++;  // Add current fruit to basket

        // If we have more than 2 types, shrink window from the left
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);  // Remove type if count is zero
            }
            left++;  // Move window start forward
        }

        maxLen = max(maxLen, right - left + 1);  // Update max length
    }

    return maxLen;
}

int main() {
    vector<int> orchard1 = {1, 2, 1};
    vector<int> orchard2 = {0, 1, 2, 2};

    cout << "Max fruits in orchard1: " << totalFruit(orchard1) << endl;
    cout << "Max fruits in orchard2: " << totalFruit(orchard2) << endl;

    return 0;
}

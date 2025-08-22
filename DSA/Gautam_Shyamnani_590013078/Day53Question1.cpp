#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(const vector<int>& nums) {
    int maxCount = 0;      // Longest streak of 1s found so far
    int currentCount = 0;  // Current streak of 1s

    for (int num : nums) {
        if (num == 1) {
            currentCount++;           // Extend the current streak
            maxCount = max(maxCount, currentCount); // Update max if needed
        } else {
            currentCount = 0;         // Reset streak on 0
        }
    }

    return maxCount;
}

int main() {
    vector<int> data1 = {1, 1, 0, 1, 1, 1};
    vector<int> data2 = {1, 0, 1, 1, 0, 1};

    cout << "Max consecutive 1s in data1: " << findMaxConsecutiveOnes(data1) << endl;
    cout << "Max consecutive 1s in data2: " << findMaxConsecutiveOnes(data2) << endl;

    return 0;
}

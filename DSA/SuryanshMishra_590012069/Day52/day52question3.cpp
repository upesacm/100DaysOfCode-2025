// 3. Trapping Rain Water
// A problem that teaches advanced two-pointer techniques and demonstrates elevation-based computation algorithms using height analysis for geometric calculation and optimization problems.

// Given n non-negative integers representing an elevation map, compute how much water it can trap after raining using two-pointer technique. This operation is fundamental in geometric computation and area calculation where you need to analyze elevation profiles and calculate trapped volumes efficiently. The technique uses two-pointer approach with height tracking to determine water levels at each position based on surrounding elevation barriers. This concept is essential in civil engineering, terrain analysis, and computational geometry where calculating trapped volumes enables water management planning and geometric optimization in elevation-based scenarios.

// This teaches geometric computation algorithms and elevation analysis techniques that are essential for volume calculation and efficient geometric optimization operations.

// Your task: Implement two-pointer elevation analysis to calculate trapped water volumes by tracking maximum heights and computing water levels efficiently.

// Examples
// Input:

// height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output:

// 6
// Input:

// height = [4,2,0,3,2,5]
// Output:

// 9
#include <iostream>
#include <vector>
using namespace std;

int trapRainWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            // Water trapped depends on leftMax
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                totalWater += leftMax - height[left];
            ++left;
        } else {
            // Water trapped depends on rightMax
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                totalWater += rightMax - height[right];
            --right;
        }
    }

    return totalWater;
}

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapRainWater(height1) << endl; // Output: 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << trapRainWater(height2) << endl; // Output: 9

    return 0;
}

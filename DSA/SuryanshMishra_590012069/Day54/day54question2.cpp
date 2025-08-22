// 2. Container With Most Water
// A problem that demonstrates geometric optimization techniques and teaches area maximization algorithms using two-pointer convergence methods for spatial analysis and optimization problems.

// Given n non-negative integers representing height, find two lines that together with the x-axis form a container that holds the most water using two-pointer optimization. This operation is fundamental in geometric optimization and area maximization where you need to find optimal boundaries that maximize enclosed space efficiently. The technique uses two-pointer convergence from array ends, moving the shorter line inward to explore potentially larger areas. This concept is essential in engineering design, resource optimization, and spatial analysis where maximizing container capacity enables efficient storage planning and geometric optimization.

// This introduces geometric optimization algorithms and area maximization techniques that are crucial for spatial analysis and efficient container optimization operations.

// Your task: Implement two-pointer convergence with height-based movement strategy to find maximum water container area through optimal boundary selection.

// Examples
// Input:

// height = [1,8,6,2,5,4,8,3,7]
// Output:

// 49
// Input:

// height = [1,1]
// Output:

// 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        max_area = max(max_area, width * h);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

int main() {
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(h1) << endl;

    vector<int> h2 = {1,1};
    cout << maxArea(h2) << endl;

    return 0;
}

#include <iostream>
#include <vector>

int trapRainWater(const std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    int trapped_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                trapped_water += left_max - height[left];
            ++left;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                trapped_water += right_max - height[right];
            --right;
        }
    }

    return trapped_water;
}

int main() {
    std::vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "Trapped water: " << trapRainWater(height1) << std::endl; // Output: 6

    std::vector<int> height2 = {4,2,0,3,2,5};
    std::cout << "Trapped water: " << trapRainWater(height2) << std::endl; // Output: 9

    return 0;
}

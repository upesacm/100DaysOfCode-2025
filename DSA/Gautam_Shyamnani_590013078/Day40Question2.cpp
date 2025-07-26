#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int max_area = 0;
    heights.push_back(0); // Append 0 as sentinel to flush stack at end

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }

    return max_area;
}

int main() {
    vector<int> example1 = {2, 1, 5, 6, 2, 3};
    vector<int> example2 = {2, 4};

    cout << largestRectangleArea(example1) << endl;  // Expected: 10
    cout << largestRectangleArea(example2) << endl;  // Expected: 4

    return 0;
}

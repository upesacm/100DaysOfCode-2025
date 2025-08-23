#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0, n = heights.size();
    int i = 0;

    while (i < n) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i++);
        } else {
            int top = s.top(); s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }

    // Remaining bars in stack
    while (!s.empty()) {
        int top = s.top(); s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[top] * width);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}

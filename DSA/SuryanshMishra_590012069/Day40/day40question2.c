// 2. Largest Rectangle in Histogram
// A problem that introduces computational geometry applications and teaches advanced monotonic stack techniques for area optimization and geometric analysis in histogram data structures.

// Given n non-negative integers representing histogram bar heights, find the area of the largest rectangle that can be formed using a stack-based approach. This operation is fundamental in computational geometry and area optimization where you need to find maximum rectangular regions within constrained boundaries. The technique uses a monotonic increasing stack to efficiently track potential rectangle boundaries, enabling O(n) time complexity for area computation. This concept is essential in image processing, architectural design, and optimization problems where maximum area calculations are crucial for space utilization and geometric analysis.

// This introduces computational geometry algorithms and area optimization techniques that are crucial for geometric analysis and efficient spatial computation operations.

// Your task: Implement a monotonic stack solution to find the maximum rectangular area by tracking height boundaries and computing optimal width extensions.

// Examples
// Input:

// [2,1,5,6,2,3]
// Output:

// 10
// Input:

// [2,4]
// Output:

// 4
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int largestRectangleArea(int* heights, int n) {
int stack[MAX];
int top = -1;
int maxArea = 0;
int i = 0;
while (i < n) {
if (top == -1 || heights[i] >= heights[stack[top]]) {
stack[++top] = i++;
} else {
int height = heights[stack[top--]];
int width = (top == -1) ? i : i - stack[top] - 1;
int area = height * width;
if (area > maxArea)
maxArea = area;
}
}
while (top != -1) {
int height = heights[stack[top--]];
int width = (top == -1) ? i : i - stack[top] - 1;
int area = height * width;
if (area > maxArea)
maxArea = area;
}
return maxArea;
}
// 1. Next Greater Element
// A problem that demonstrates monotonic stack techniques and teaches efficient nearest greater
// element finding algorithms for array processing and optimization problems.
// For each element in the array, find the next greater element to the right using a stack-based
// approach. If there is no greater element, assign -1. This operation is fundamental
// in algorithmic optimization and array processing where you need to identify nearest
// greater values efficiently. The technique uses a monotonic stack to maintain elements in
// decreasing order, enabling O(n) time complexity instead of the naive O(n²) approach. This
// concept is essential in stock span problems, histogram analysis, and competitive
// programming where efficient nearest element queries are crucial for performance
// optimization.
// This teaches monotonic stack algorithms and nearest greater element techniques that are
// essential for array optimization and efficient element comparison operations.
// Your task: Implement a monotonic stack solution to find the next greater element for each
// array position in linear time complexity.
// Examples
// Input:
// [4, 5, 2, 25]
// Output:
// [5, 25, 25, -1]
// Input:
// [13, 7, 6, 12]
// Output:
// [-1, 12, 12, -1]
#include <stdio.h>
#include <stdlib.h>
void nextGreaterElement(int *arr, int n) {
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[stack[top]] < arr[i]) {
            result[stack[top]] = arr[i];
            top--;
        }
        stack[++top] = i;
    }
    printf("Next greater elements: ");  
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    free(stack);
}    
int main(){
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    nextGreaterElement(arr1, n1);

    int arr2[] = {13, 7, 6, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    nextGreaterElement(arr2, n2);

    return 0;
}

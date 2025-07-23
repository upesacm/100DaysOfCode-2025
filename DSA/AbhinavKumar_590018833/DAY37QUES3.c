// 3. Delete Middle Element of Stack
// A problem that teaches precision stack manipulation and demonstrates recursive techniques for accessing and modifying specific stack positions using positional algorithms.

// Given a stack, delete its middle element using only stack operations and recursion without converting to other data structures. This operation requires understanding positional calculations in stacks and implementing recursive traversal to reach specific elements while preserving the order of remaining elements. The technique is important in data structure maintenance where you need to remove specific elements from constrained access structures. This concept teaches recursive stack traversal and selective element removal techniques that are essential for advanced stack-based algorithms and data manipulation operations.

// This teaches recursive stack traversal and positional element manipulation techniques that are essential for advanced data structure operations and selective element processing.

// Your task: Implement recursive stack operations to locate and remove the middle element while maintaining the original order of all other elements.

// Examples
// Input:

// [1, 2, 3, 4, 5]
// Output:

// [1, 2, 4, 5]
// Input:

// [10, 20, 30]
// Output:

// [10, 30]
#include <stdio.h>

#include <stdlib.h>
void deleteMiddleElement(int *stack, int n) {
    if (n == 0) return; 
    if (n == 1) return; 

    int mid = n / 2;
    int temp = stack[mid];

    for (int i = mid; i < n - 1; i++) {
        stack[i] = stack[i + 1];
    }

    printf("Stack after deleting middle element (%d): ", temp);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    int stack1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    deleteMiddleElement(stack1, n1);

    int stack2[] = {10, 20, 30};
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    deleteMiddleElement(stack2, n2);

    return 0;
}
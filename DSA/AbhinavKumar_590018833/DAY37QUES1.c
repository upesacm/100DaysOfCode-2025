// 1. Sort a Stack using Another Stack
// A problem that demonstrates advanced stack manipulation techniques and teaches efficient sorting algorithms using only stack-based operations without auxiliary data structures.

// Given a stack of integers, sort it in ascending order using only another stack as auxiliary storage (no arrays, lists, or other data structures allowed). This operation challenges traditional sorting approaches and requires understanding stack-based sorting algorithms that work within the constraints of LIFO operations. The technique is crucial in memory-constrained environments where you need to sort data efficiently using minimal additional space. This approach teaches how to leverage temporary stack storage for organizing data while maintaining the fundamental properties of stack operations throughout the sorting process.

// This teaches constrained sorting algorithms and stack-based data organization techniques that are essential for memory-efficient sorting and space-optimized algorithmic solutions.

// Your task: Implement a sorting algorithm using only stack operations and one additional stack as temporary storage for efficient data organization.

// Examples
// Input:

// [3, 1, 4, 2]
// Output:

// [1, 2, 3, 4]
// Input:

// [6, 5, 8]
// Output:

// [5, 6, 8]
#include<stdio.h>
#include<stdlib.h>
void sortStack(int *input, int n) {
    int *tempStack = (int *)malloc(n * sizeof(int));
    int topInput = -1, topTemp = -1;

    for (int i = 0; i < n; i++) {
        while (topTemp != -1 && tempStack[topTemp] > input[i]) {
            input[++topInput] = tempStack[topTemp--];
        }
        tempStack[++topTemp] = input[i];
    }

    while (topTemp != -1) {
        input[++topInput] = tempStack[topTemp--];
    }

    free(tempStack);
}
int main() {
    int arr[] = {3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortStack(arr, n);

    printf("Sorted stack: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
// 1. Reverse a Stack using Recursion
// A problem that demonstrates advanced recursive techniques and teaches in-place data
// structure manipulation without auxiliary storage through systematic recursive operations.
// Reverse the elements of a stack without using any extra space (use recursion only). This
// operation challenges traditional reversal approaches by eliminating auxiliary data structures
// and relying purely on recursive call stack for temporary storage. The technique is
// fundamental in space-constrained algorithms and in-place manipulation where you need
// to transform data structures without additional memory allocation. Understanding this
// concept is crucial for memory-efficient programming and recursive problem
// solving where the call stack itself becomes the working storage. This approach
// teaches advanced recursion patterns that are essential for implementing complex
// transformations with minimal space overhead.
// This teaches in-place recursive algorithms and call stack utilization techniques that are
// essential for memory-efficient data structure manipulation and space-optimized
// recursive operations.
// Your task: Implement recursive stack reversal using only the implicit call stack as temporary
// storage while maintaining O(1) auxiliary space complexity.
// Examples
// Input:
// [1, 2, 3]
// Output:
// [3, 2, 1]
// Input:
// [5, 6]
// Output:
// [6, 5]
#include<stdio.h>
#include<stdlib.h>
void printStack(int *stack,int n){
    for(int i=0;i<n;i++) printf("%d ", stack[i]);
    printf("\n");
}
void reverseStack(int *stack,int n){
    if(n<=0) return;
    int top=stack[n-1];
    reverseStack(stack,n-1);
    for(int i=n-1;i>0;i--) stack[i]=stack[i-1];
    stack[0]=top;
    printf("Reversed Stack: ");
    for (int i=0;i<n;i++) printf("%d ", stack[i]);
    printf("\n");
    free(stack); 
    return;


} 
int main() {
    int stack1[] = {1, 2, 3};
    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    printf("Original Stack: ");
    printStack(stack1, n1);
    reverseStack(stack1, n1);

    int stack2[] = {5, 6};
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    printf("Original Stack: ");
    printStack(stack2, n2);
    reverseStack(stack2, n2);

    return 0;
}

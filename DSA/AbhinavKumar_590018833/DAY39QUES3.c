// //3. Implement 2 Stacks in an Array
// A problem that teaches space-efficient data structure design and demonstrates optimal
// memory utilization techniques for implementing multiple stacks within shared storage
// constraints.
// Design a data structure that implements two stacks in one array such that neither stack
// overflows until the total space is used. This operation requires understanding space
// partitioning strategies and dynamic boundary management where you need to maximize
// space utilization while maintaining stack properties. The technique is crucial in embedded
// systems and memory-constrained environments where you need efficient multi-stack
// implementations without wasting allocated space. This concept teaches optimal space
// allocation and collision detection that are essential for building efficient container classes
// and system-level data structures.
// This teaches space-efficient container design and memory optimization techniques that
// are essential for system programming and resource-constrained data structure
// implementations.
// Your task: Design a dual-stack array implementation with optimal space utilization by
// managing dynamic boundaries and preventing premature overflow conditions.
// Examples
// Input:
// Push 1, 2 in stack1, Push 9, 8 in stack2
// Output:
// Stack1: [1, 2], Stack2: [8, 9]
// Input:
// Push 3 in stack1, Pop stack2
// Output:
// Stack1: [1, 2, 3], Stack2: [8] 
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int top1;
    int top2;
    int capacity;
} TwoStacks;
void initTwoStacks(TwoStacks *stacks, int capacity) {
    stacks->data = (int *)malloc(capacity * sizeof(int));
    stacks->top1 = -1;
    stacks->top2 = capacity;
    stacks->capacity = capacity;
}
void push1(TwoStacks *stacks, int value) {
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack 1 overflow\n");
        return;
    }
    stacks->data[++stacks->top1] = value;
}
void push2(TwoStacks *stacks,int value){
    if (stacks->top2 - 1 == stacks->top1) {
        printf("Stack 2 overflow\n");
        return;
    }
    stacks->data[--stacks->top2] = value;
}
void pop1(TwoStacks *stacks){
    if (stacks->top1 == -1) {
        printf("Stack 1 underflow\n");
        return;
    }
    stacks->top1--;
}
void pop2(TwoStacks *stacks){
    if (stacks->top2 == stacks->capacity) {
        printf("Stack 2 underflow\n");
        return;
    }
    stacks->top2++;
}
int top1(TwoStacks *stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 is empty\n");
        return -1;
    }
    return stacks->data[stacks->top1];
}
int top2(TwoStacks *stacks){
    if (stacks->top2 == stacks->capacity) {
        printf("Stack 2 is empty\n");
        return -1;
    }
    return stacks->data[stacks->top2];
}
int main(){
    TwoStacks stacks;
    initTwoStacks(&stacks, 100);

    push1(&stacks, 1);
    push1(&stacks, 2);
    push2(&stacks, 9);
    push2(&stacks, 8);
    
    printf("Stack1: ");
    for (int i = 0; i <= stacks.top1; i++) {
        printf("%d ", stacks.data[i]);
    }
    printf("\nStack2: ");
    for (int i = stacks.top2; i < stacks.capacity; i++) {
        printf("%d ", stacks.data[i]);
    }
    printf("\n");

    push1(&stacks, 3);
    pop2(&stacks);

    printf("After pushing 3 in Stack1 and popping Stack2:\n");
    printf("Stack1: ");
    for (int i = 0; i <= stacks.top1; i++) {
        printf("%d ", stacks.data[i]);
    }
    printf("\nStack2: ");
    for (int i = stacks.top2; i < stacks.capacity; i++) {
        printf("%d ", stacks.data[i]);
    }
    
    free(stacks.data);
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int* stack;
    int* minStack;
    int top;
    int minTop;
    int capacity;
} MinStack;
MinStack* minStackCreate(int capacity) {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->stack = (int*)malloc(capacity * sizeof(int));
    minStack->minStack = (int*)malloc(capacity * sizeof(int));
    minStack->top = -1;
    minStack->minTop = -1;
    minStack->capacity = capacity;
    return minStack;
}
void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}
void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
int main() {
    MinStack* minStack = minStackCreate(100);
    minStackPush(minStack, 5);
    minStackPush(minStack, 3);
    minStackPush(minStack, 7);
    printf("%d\n", minStackGetMin(minStack));
    minStackPush(minStack, 8);
    minStackPush(minStack, 2);
    printf("%d\n", minStackGetMin(minStack));
    minStackPop(minStack);
    printf("%d\n", minStackGetMin(minStack));
    minStackFree(minStack);
    return 0;
}
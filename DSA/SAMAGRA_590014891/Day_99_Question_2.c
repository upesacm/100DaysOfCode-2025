#include <stdio.h>

#define MAX 1000

typedef struct {
    int val;
    int maxVal;
} StackNode;

StackNode stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push(StackNode stack[], int *top, int value) {
    int maxVal = value;
    if (*top >= 0 && stack[*top].maxVal > maxVal)
        maxVal = stack[*top].maxVal;
    stack[++(*top)] = (StackNode){value, maxVal};
}

int pop(StackNode stack[], int *top) {
    return stack[(*top)--].val;
}

int getMax(StackNode stack[], int top) {
    if (top == -1) return -1e9;
    return stack[top].maxVal;
}

void transfer() {
    while (top1 >= 0) {
        int val = pop(stack1, &top1);
        push(stack2, &top2, val);
    }
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    for (int i = 0; i < n; i++) {
        push(stack1, &top1, arr[i]);
        if (i >= k-1) {
            if (top2 == -1) transfer();
            int max1 = getMax(stack1, top1);
            int max2 = getMax(stack2, top2);
            int windowMax = (max1 > max2) ? max1 : max2;
            printf("%d ", windowMax);
            pop(stack2, &top2);
        }
    }
    return 0;
}

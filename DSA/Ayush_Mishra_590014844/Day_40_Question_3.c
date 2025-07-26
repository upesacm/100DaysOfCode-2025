#include <stdio.h>
#include <limits.h>

int stack[100], maxStack[100], top = -1, maxTop = -1;

void push(int val) {
    stack[++top] = val;
    if (maxTop == -1 || val >= maxStack[maxTop])
        maxStack[++maxTop] = val;
    else
        maxStack[maxTop + 1] = maxStack[maxTop], maxTop++;
}

void pop() {
    if (top == -1) return;
    top--;
    maxTop--;
}

int getMax() {
    if (maxTop == -1) return INT_MIN;
    return maxStack[maxTop];
}

int main() {
    int q, type, val;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            push(val);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            printf("%d\n", getMax());
        }
    }
    return 0;
}

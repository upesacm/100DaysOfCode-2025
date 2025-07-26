#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 < top2 - 1)
        arr[++top1] = x;
    else
        printf("Stack Overflow in Stack1\n");
}

void push2(int x) {
    if (top1 < top2 - 1)
        arr[--top2] = x;
    else
        printf("Stack Overflow in Stack2\n");
}

int pop1() {
    if (top1 >= 0)
        return arr[top1--];
    printf("Stack Underflow in Stack1\n");
    return -1;
}

int pop2() {
    if (top2 < MAX)
        return arr[top2++];
    printf("Stack Underflow in Stack2\n");
    return -1;
}

void printStacks() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Stack2: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    push1(1);
    push1(2);
    push2(9);
    push2(8);

    printStacks();

    push1(3);
    pop2();

    printStacks();

    return 0;
}

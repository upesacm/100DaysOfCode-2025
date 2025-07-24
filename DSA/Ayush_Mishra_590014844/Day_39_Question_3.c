#include <stdio.h>
#define SIZE 100
int arr[SIZE], top1 = -1, top2 = SIZE;

void push1(int val) {
    if (top1 + 1 == top2) return;
    arr[++top1] = val;
}

void push2(int val) {
    if (top2 - 1 == top1) return;
    arr[--top2] = val;
}

int pop1() {
    if (top1 == -1) return -1;
    return arr[top1--];
}

int pop2() {
    if (top2 == SIZE) return -1;
    return arr[top2++];
}

void print1() {
    for (int i = 0; i <= top1; ++i) printf("%d ", arr[i]);
    printf("\n");
}

void print2() {
    for (int i = SIZE - 1; i >= top2; --i) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    push1(1);
    push1(2);
    push2(9);
    push2(8);
    print1();
    print2();
    push1(3);
    pop2();
    print1();
    print2();
    return 0;
}

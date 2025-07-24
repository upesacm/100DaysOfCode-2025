#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void insert_bottom(int val) {
    if (top == -1) {
        push(val);
        return;
    }
    int temp = pop();
    insert_bottom(val);
    push(temp);
}

void reverse() {
    if (top == -1) return;
    int temp = pop();
    reverse();
    insert_bottom(temp);
}

int main() {
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        push(val);
    }
    reverse();
    for (int i = 0; i <= top; ++i)
        printf("%d ", stack[i]);
    return 0;
}

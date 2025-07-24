#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;
void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void deleteMiddle(int current, int mid) {
    if (top == -1) return;

    int temp = pop();

    if (current != mid) {
        deleteMiddle(current + 1, mid);
        push(temp);  
    } else {
        deleteMiddle(current + 1, mid);
    }
}

void printStackBottomToTop() {
    printf("[");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i != top) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stack elements (bottom to top):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Input: ");
    printStackBottomToTop();

    int mid = n / 2;  

    deleteMiddle(0, mid);

    printf("Output: ");
    printStackBottomToTop();

    return 0;
}

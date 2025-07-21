
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void deleteMiddle(int current, int size) {
    if (current == size / 2) {
        pop();
        return;
    }

    int temp = pop();
    deleteMiddle(current + 1, size);
    push(temp);
}

void printStack() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    deleteMiddle(0, n);

    printf("Stack after deleting middle element:\n");
    printStack();

    return 0;
}

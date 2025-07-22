#include <stdio.h>
#define MAX 100

void sortStack(int* stack, int* top) {
    int tempStack[MAX], top2 = -1;

    while (*top >= 0) {
        int temp = stack[(*top)--];

        while (top2 >= 0 && tempStack[top2] > temp) {
            stack[++(*top)] = tempStack[top2--];
        }
        tempStack[++top2] = temp;
    }

    while (top2 >= 0) {
        stack[++(*top)] = tempStack[top2--];
    }
}

void printStack(int* stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX], top = -1;

    stack[++top] = 3;
    stack[++top] = 1;
    stack[++top] = 4;
    stack[++top] = 2;

    sortStack(stack, &top);
    printStack(stack, top); 

    return 0;
}


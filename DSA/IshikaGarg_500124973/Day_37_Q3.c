
#include <stdio.h>
#define MAX 100

void deleteMiddle(int* stack, int* top, int current, int size) {
    if (current == size / 2) {
        (*top)--;
        return;
    }

    int temp = stack[(*top)--];
    deleteMiddle(stack, top, current + 1, size);
    stack[++(*top)] = temp;
}

void deleteMiddleElement(int* stack, int* top) {
    int size = *top + 1;
    deleteMiddle(stack, top, 0, size);
}

void printStack(int* stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX], top = -1;
    stack[++top] = 1;
    stack[++top] = 2;
    stack[++top] = 3;
    stack[++top] = 4;
    stack[++top] = 5;

    deleteMiddleElement(stack, &top);
    printStack(stack, top); 

    return 0;
}

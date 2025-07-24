#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;
int sortedStack[MAX_SIZE], sortedTop = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

void pushSorted(int data) {
    if (sortedTop == MAX_SIZE - 1) {
        printf("Sorted stack overflow!\n");
        return;
    }
    sortedTop++;
    sortedStack[sortedTop] = data;
}

int popSorted() {
    if (sortedTop == -1) {
        printf("Sorted stack underflow!\n");
        return -1;
    }
    int data = sortedStack[sortedTop];
    sortedTop--;
    return data;
}

void sort_stack() {
    int temp;
    while (top != -1) {
        temp = pop();
        while (sortedTop != -1 && sortedStack[sortedTop] < temp) {
            push(popSorted());
        }
        pushSorted(temp);
    }
    while (sortedTop != -1) {
        push(popSorted());
    }
}

void print_stack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(3);
    push(1);
    push(4);
    push(2);

    printf("Original stack: ");
    print_stack();

    sort_stack();

    printf("Sorted stack:   ");
    print_stack();

    return 0;
}

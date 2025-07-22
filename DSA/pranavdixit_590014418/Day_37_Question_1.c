#include <stdio.h>

#define MAX 100

int stack[MAX];
int temp[MAX];
int top = -1;
int tempTop = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void tempPush(int x) {
    temp[++tempTop] = x;
}

int tempPop() {
    return temp[tempTop--];
}

int isEmpty() {
    return top == -1;
}

void sortStack() {
    while (!isEmpty()) {
        int curr = pop();
        while (tempTop != -1 && temp[tempTop] > curr) {
            push(tempPop());
        }
        tempPush(curr);
    }

    while (tempTop != -1) {
        push(tempPop());
    }
}

void printStack() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(3);
    push(1);
    push(4);
    push(2);

    sortStack();

    printStack();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void deleteMiddle(Stack *s, int curr, int mid) {
    if (curr == mid) {
        pop(s);
        return;
    }
    int temp = pop(s);
    deleteMiddle(s, curr + 1, mid);
    push(s, temp);
}

void printStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }

    int mid = s.top / 2;
    deleteMiddle(&s, 0, mid);

    printStack(&s);
    return 0;
}
Footer

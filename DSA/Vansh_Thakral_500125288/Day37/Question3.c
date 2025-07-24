#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

void deleteMiddle(Stack *s, int current, int middle) {
    if (s->top == -1) return;

    int temp = pop(s);

    if (current != middle)
        deleteMiddle(s, current + 1, middle);
    else
        deleteMiddle(s, current + 1, middle); 

    if (current != middle)
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
    s.top = -1;

    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    int mid = s.top / 2;
    deleteMiddle(&s, 0, mid);

    printStack(&s);  

    return 0;
}


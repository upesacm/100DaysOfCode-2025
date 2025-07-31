#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int x) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = x;
    }
}
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}
void insertAtBottom(Stack* s, int x) {
    if (isEmpty(s)) {
        push(s, x);
    } else {
        int temp = pop(s);
        insertAtBottom(s, x);
        push(s, temp);
    }
}
void printStack(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    
    int x = 0;
    printf("Original Stack: ");
    printStack(&s);
    
    insertAtBottom(&s, x);
    
    printf("Stack after inserting %d at the bottom: ", x);
    printStack(&s);
    
    return 0;
}

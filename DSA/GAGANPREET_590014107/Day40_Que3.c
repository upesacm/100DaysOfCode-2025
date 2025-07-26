#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return -1; 

}

int peek(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top];
    }
    return -1;
}

typedef struct {
    Stack mainStack;
    Stack maxStack;
} MaxStack;

void initMaxStack(MaxStack *ms) {
    init(&(ms->mainStack));
    init(&(ms->maxStack));
}
void pushMax(MaxStack *ms, int value) {
    push(&(ms->mainStack), value);
    if (ms->maxStack.top == -1 || value >= peek(&(ms->maxStack))) {
        push(&(ms->maxStack), value);
    }
}

int popMax(MaxStack *ms) {
    int popped = pop(&(ms->mainStack));
    if (popped == peek(&(ms->maxStack))) {
        pop(&(ms->maxStack));
    }
    return popped;
}

int getMax(MaxStack *ms) {
    return peek(&(ms->maxStack));
}

int main() {
    MaxStack ms;
    initMaxStack(&ms);

    pushMax(&ms, 3);
    pushMax(&ms, 5);
    pushMax(&ms, 2);
    printf("Current Max: %d\n", getMax(&ms));  

    popMax(&ms);
    printf("Current Max after pop: %d\n", getMax(&ms)); 

    popMax(&ms);
    printf("Current Max after another pop: %d\n", getMax(&ms));  

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct MaxStack {
    int* mainStack;
    int* maxStack;
    int capacity;
    int top;
};

void init(struct MaxStack* s, int capacity) {
    s->capacity = capacity;
    s->mainStack = (int*)malloc(capacity * sizeof(int));
    s->maxStack = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
}

int isEmpty(struct MaxStack* s) {
    return s->top == -1;
}

void push(struct MaxStack* s, int x) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->mainStack[s->top] = x;

    if (s->top == 0)
        s->maxStack[s->top] = x;
    else
        s->maxStack[s->top] = (x > s->maxStack[s->top - 1]) ? x : s->maxStack[s->top - 1];
}

int pop(struct MaxStack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->mainStack[s->top--];
}

int getMax(struct MaxStack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->maxStack[s->top];
}

void destroy(struct MaxStack* s) {
    free(s->mainStack);
    free(s->maxStack);
}

int main() {
    int capacity = 100;
    struct MaxStack s;
    init(&s, capacity);

   
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    printf("Max: %d\n", getMax(&s));  

    pop(&s);  
    printf("Max: %d\n", getMax(&s));

    pop(&s); 
    printf("Max: %d\n", getMax(&s)); 

    destroy(&s);
    return 0;
}

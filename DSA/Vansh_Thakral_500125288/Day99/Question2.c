#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int val;
    int max;
} StackNode;

typedef struct {
    StackNode arr[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }

void push(Stack* s, int val) {
    int m = isEmpty(s) ? val : (val > s->arr[s->top].max ? val : s->arr[s->top].max);
    s->arr[++s->top].val = val;
    s->arr[s->top].max = m;
}

int pop(Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top--].val;
}

int getMax(Stack* s) {
    if (isEmpty(s)) return -1e9;
    return s->arr[s->top].max;
}

// Transfer elements from s1 to s2
void transfer(Stack* s1, Stack* s2) {
    while (!isEmpty(s1)) {
        int val = pop(s1);
        push(s2, val);
    }
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    Stack s1, s2;
    init(&s1); init(&s2);

    for (int i = 0; i < n; i++) {
        push(&s1, arr[i]);

        if (i >= k - 1) {
            if (isEmpty(&s2)) transfer(&s1, &s2);
            int windowMax = getMax(&s1) > getMax(&s2) ? getMax(&s1) : getMax(&s2);
            printf("%d ", windowMax);

            // Remove outgoing element
            if (getMax(&s2) != -1e9) pop(&s2);
        }
    }
    return 0;
}

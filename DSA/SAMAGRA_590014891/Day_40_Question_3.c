#include <stdio.h>
#include <limits.h>

#define MAX 10000

typedef struct {
    int stack[MAX], max_stack[MAX], top, max_top;
} MaxStack;

void init(MaxStack* s) {
    s->top = s->max_top = -1;
}

void push(MaxStack* s, int val) {
    s->stack[++s->top] = val;
    if (s->max_top == -1 || val >= s->max_stack[s->max_top])
        s->max_stack[++s->max_top] = val;
}

int pop(MaxStack* s) {
    if (s->top == -1) return INT_MIN;
    int val = s->stack[s->top--];
    if (val == s->max_stack[s->max_top]) s->max_top--;
    return val;
}

int getMax(MaxStack* s) {
    if (s->max_top == -1) return INT_MIN;
    return s->max_stack[s->max_top];
}

int main() {
    MaxStack s;
    init(&s);
    int q;
    scanf("%d", &q);
    while (q--) {
        char op[10];
        int x;
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%d", &x);
            push(&s, x);
        } else if (op[0] == 'p') {
            pop(&s);
        } else if (op[0] == 'g') {
            printf("%d\n", getMax(&s));
        }
    }
    return 0;
}

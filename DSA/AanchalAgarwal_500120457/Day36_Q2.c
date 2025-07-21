#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Stack structure
struct Stack {
    char items[MAX];
    int top;
};

// Stack functions
void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = c;
    }
}

char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peek(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char expr[]) {
    struct Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0; // Not balanced
            }
        }
    }

    return isEmpty(&s); // If stack is empty, balanced
}

int main() {
    char expr1[] = "([])";
    char expr2[] = "([";
    
    printf("%s -> %s\n", expr1, isBalanced(expr1) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", expr2, isBalanced(expr2) ? "Balanced" : "Not Balanced");

    return 0;
}

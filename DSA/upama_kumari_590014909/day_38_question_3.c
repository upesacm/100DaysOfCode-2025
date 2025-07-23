#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char ch) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = ch;
    }
}
char pop(Stack *s) {
    if (s->top >= 0)
        return s->data[(s->top)--];
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0)
        return s->data[s->top];
    return '\0';
}

int hasRedundantBrackets(char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == ')') {
            int operatorFound = 0;
            while (! (peek(&s) == '(')) {
                char top = pop(&s);
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = 1;
                }
            }
            pop(&s); 

            if (!operatorFound)
                return 1; 
        } else {
            push(&s, ch);
        }
    }

    return 0;  
}
int main() {
    char expr[] = "((a+b))";

    if (hasRedundantBrackets(expr)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

struct Stack {
    int top;
    char items[MAX];
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char ch) {
    if (!isFull(s)) {
        s->items[++(s->top)] = ch;
    }
}

char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';  
}

void reverseString(char *str) {
    struct Stack s;
    initStack(&s);

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    for (i = 0; !isEmpty(&s); i++) {
        str[i] = pop(&s);
    }
    str[i] = '\0';  
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct Stack {
    char arr[MAX];
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

void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = c;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || 
           (opening == '{' && closing == '}') || 
           (opening == '[' && closing == ']');
}

int isBalanced(char* str) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), str[i])) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;

    if (isBalanced(str)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    
    return 0;
}

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
void reverseString(char* str) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }   
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&s);
    }
}
int main() {
    char str[MAX];   
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

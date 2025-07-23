#include <stdio.h>
#include <string.h>
#define MAX 100


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
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = ch;
}


char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}


void reverseString(char str[]) {
    struct Stack s;
    initStack(&s);

   
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

 
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str1[] = "hello";
    char str2[] = "abcde";

    reverseString(str1);
    printf("Reversed: %s\n", str1);  // Output: olleh

    reverseString(str2);
    printf("Reversed: %s\n", str2);  // Output: edcba

    return 0;
}

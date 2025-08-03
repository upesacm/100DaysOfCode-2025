#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    char data[MAX];
    int top;
} Stack;
void init(Stack* s) 
{
    s->top = -1;
}
int isEmpty(Stack* s) 
{
    return s->top == -1;
}
void push(Stack* s, char ch) 
{
    if (s->top == MAX - 1) 
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = ch;
}
char pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
char peek(Stack* s) 
{
    if (isEmpty(s)) 
    {
        return '\0';
    }
    return s->data[s->top];
}
int hasRedundantBrackets(char* expr) 
{
    Stack s;
    init(&s);
    for (int i = 0; expr[i] != '\0'; i++) 
    {
        char ch = expr[i];
        if (ch == ')') 
        {
            int hasOperator = 0;
            while (!isEmpty(&s) && peek(&s) != '(') 
            {
                char top = pop(&s);
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = 1;
                }
            }
            if (!isEmpty(&s) && peek(&s) == '(') 
            {
                pop(&s);
            }
            if (!hasOperator) 
            {
                return 1; 
            }
        } else {
            push(&s, ch);
        }
    }
    return 0; 
}

int main() 
{
    char expr[MAX];
    printf("Enter a valid mathematical expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; 
    if (hasRedundantBrackets(expr)) 
    {
        printf("The expression contains redundant brackets.\n");
    } 
    else 
    {
        printf("The expression does not contain redundant brackets.\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    int data[MAX];
    int top;
} Stack;
void init(Stack *s) 
{
    s->top = -1;
}
int isEmpty(Stack *s) 
{
    return s->top == -1;
}
void push(Stack *s, int value) 
{
    if (s->top == MAX - 1) 
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}
int pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
int evaluatePostfix(char *expr) 
{
    Stack stack;
    init(&stack);
    int i = 0;
    while (expr[i]) 
    {
        if (expr[i] == ' ') 
        {
            i++;
            continue;
        }
        else if (isdigit(expr[i])) 
        {
            int num = 0;
            while (isdigit(expr[i])) 
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else 
        {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (expr[i]) 
            {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default:
                    printf("Unsupported operator: %c\n", expr[i]);
                    exit(1);
            }
            push(&stack, result);
            i++;
        }
    }
    return pop(&stack);
}
int main() 
{
    char expr[MAX];
    printf("Enter a postfix expression (tokens separated by space):\n");
    fgets(expr, MAX, stdin);
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}

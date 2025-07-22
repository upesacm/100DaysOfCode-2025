#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Stack 
{
    char arr[MAX];
    int top;
};
void initStack(struct Stack* stack)
{
    stack->top = -1;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
void push(struct Stack* stack, char ch) 
{
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = ch;
    }
}
char pop(struct Stack* stack) 
{
    if (!isEmpty(stack)) 
    {
        return stack->arr[stack->top--];
    }
    return '\0';
}
int isMatchingPair(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int isBalanced(char* expr) 
{
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) 
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) 
            {
                return 0; 
            }
        }
    }
    return isEmpty(&stack);
}
int main() 
{
    char expr[MAX];
    printf("Enter an expression with parentheses: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0; 
    if (isBalanced(expr)) 
    {
        printf("Balanced parentheses.\n");
    } else 
    {
        printf("Unbalanced parentheses.\n");
    }
    return 0;
}

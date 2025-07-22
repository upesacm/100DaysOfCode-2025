#include <stdio.h>
#include <string.h>
#define MAX 100
struct Stack {
    char arr[MAX];
    int top;
};
void initStack(struct Stack* stack) 
{
    stack->top = -1;
}
int isFull(struct Stack* stack) 
{
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}
void push(struct Stack* stack, char ch) 
{
    if (!isFull(stack)) 
    {
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
int main() 
{
    struct Stack stack;
    char str[MAX];
    int i;
    initStack(&stack);
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = 0;k
    for (i = 0; str[i] != '\0'; i++) 
  {
        push(&stack, str[i]);
    }
    printf("Reversed string: ");
    while (!isEmpty(&stack)) 
    {
        printf("%c", pop(&stack));
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main()
{
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else
        {
            int b = pop();
            int a = pop();
            switch (exp[i])
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                push(a / b);
                break;
            }
        }
    }

    printf("Result: %d\n", pop());
    return 0;
}

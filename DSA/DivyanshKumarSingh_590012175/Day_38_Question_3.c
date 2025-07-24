#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isOp(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int main()
{
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == ')')
        {
            int foundOp = 0;
            while (top != -1 && stack[top] != '(')
            {
                if (isOp(stack[top]))
                    foundOp = 1;
                top--;
            }
            if (!foundOp)
            {
                printf("Yes\n");
                return 0;
            }
            top--;
        }
        else
        {
            stack[++top] = expr[i];
        }
    }

    printf("No\n");
    return 0;
}

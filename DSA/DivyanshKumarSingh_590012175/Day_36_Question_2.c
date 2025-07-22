#include <stdio.h>

#define MAX 100

int match(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int main()
{
    char s[MAX], stack[MAX];
    int top = -1;
    printf("Enter expression: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack[++top] = s[i];
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1 || !match(stack[top--], s[i]))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}

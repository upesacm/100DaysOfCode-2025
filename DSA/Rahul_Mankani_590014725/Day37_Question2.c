#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int stk[MAX], top = -1;
void push(int x) 
{
    if (top < MAX - 1) stk[++top] = x;
}
int pop() 
{
    if (top >= 0) return stk[top--];
    return -1;
}
int evaluate(char *s) 
{
    for (int i = 0; s[i]; i++) 
    {
        if (isdigit(s[i])) 
        {
            push(s[i] - '0');
        } 
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
        {
            int b = pop(), a = pop();
            if (a == -1 || b == -1) return -1;
            switch (s[i]) 
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(b ? a / b : -1); break;
            }
        }
    }
    return pop();
}
int main() 
{
    char s[MAX];
    printf("Enter postfix expression (single digits, no spaces): ");
    scanf("%s", s);
    int result = evaluate(s);
    if (result == -1) printf("Invalid expression\n");
    else printf("Result: %d\n", result);
    return 0;
}

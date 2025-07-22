#include <stdio.h>
#include <string.h>
#define MAX 100

char stk[MAX];
int top = -1;
void push(char c) 
{
    if (top < MAX - 1) stk[++top] = c;
}
char pop() 
{
    if (top >= 0) return stk[top--];
    return '\0';
}
int match(char open, char close) 
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int balanced(char *s) 
{
    int i;
    for (i = 0; s[i]; i++) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
        {
            push(s[i]);
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
        {
            char top_char = pop();
            if (!top_char || !match(top_char, s[i])) return 0;
        }
    }
    return top == -1;
}
int main() 
{
    char s[MAX];
    printf("Enter string with parentheses: ");
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0;
    printf(balanced(s) ? "Balanced\n" : "Not Balanced\n");
    return 0;
}

#include <stdio.h>
#include <string.h>
#define MAX 100

char s[MAX], stk[MAX];
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
int main() 
{
    printf("Enter string: ");
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0;
    int i, len = strlen(s);
    for (i = 0; i < len; i++) push(s[i]);
    for (i = 0; i < len; i++) s[i] = pop();
    printf("Reversed: %s\n", s);
    return 0;
}

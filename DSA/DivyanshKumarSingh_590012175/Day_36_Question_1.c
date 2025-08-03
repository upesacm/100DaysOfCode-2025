#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char s[MAX], stack[MAX];
    int top = -1;
    printf("Enter a string: ");
    scanf("%s", s);

    int n = strlen(s);
    for (int i = 0; i < n; i++)
        stack[++top] = s[i];
    for (int i = 0; i < n; i++)
        s[i] = stack[top--];

    printf("Reversed string: %s\n", s);
    return 0;
}

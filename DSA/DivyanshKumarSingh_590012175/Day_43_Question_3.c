#include <stdio.h>
#include <string.h>

#define MAX 100

int isPalindrome(char queue[], int n)
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (queue[i] != stack[top--])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char q1[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    char q2[] = {'a', 'b', 'c'};

    if (isPalindrome(q1, 7))
        printf("Yes\n");
    else
        printf("No\n");

    if (isPalindrome(q2, 3))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

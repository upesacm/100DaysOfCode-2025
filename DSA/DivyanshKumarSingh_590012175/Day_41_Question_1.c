#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeAdjacentDuplicates(char *str)
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; str[i]; i++)
    {
        if (top >= 0 && stack[top] == str[i])
        {
            top--; // Remove duplicate
        }
        else
        {
            stack[++top] = str[i];
        }
    }

    stack[top + 1] = '\0';
    printf("Reduced String: %s\n", stack);
}

int main()
{
    char str1[] = "abbaca";
    char str2[] = "azxxzy";

    printf("Original: %s\n", str1);
    removeAdjacentDuplicates(str1);

    printf("Original: %s\n", str2);
    removeAdjacentDuplicates(str2);

    return 0;
}

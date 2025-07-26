#include <stdio.h>
#include <string.h>

void removeKdigits(char *num, int k)
{
    int len = strlen(num), top = -1;
    char stack[len + 1];

    for (int i = 0; i < len; i++)
    {
        while (k > 0 && top >= 0 && stack[top] > num[i])
        {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    top -= k; // Remove extra digits if any

    // Remove leading zeros
    int idx = 0;
    while (idx <= top && stack[idx] == '0')
        idx++;

    if (idx > top)
        printf("0\n");
    else
    {
        stack[top + 1] = '\0';
        printf("Smallest: %s\n", stack + idx);
    }
}

int main()
{
    removeKdigits("1432219", 3); // Output: "1219"
    removeKdigits("10200", 1);   // Output: "200"
    removeKdigits("10", 2);      // Output: "0"
    return 0;
}

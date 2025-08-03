
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX], stack[MAX];
    int top = -1;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        stack[++top] = str[i];

    printf("Reversed string: ");
    while (top >= 0)
        printf("%c", stack[top--]);

    printf("\n");
    return 0;
}

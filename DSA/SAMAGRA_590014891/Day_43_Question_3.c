#include <stdio.h>
#include <string.h>
#define MAX 100

int isQueuePalindrome(char q[], int len) {
    char stack[MAX];
    int top = -1;
    for (int i = 0; i < len; i++)
        stack[++top] = q[i];
    for (int i = 0; i < len; i++)
        if (q[i] != stack[top--])
            return 0;
    return 1;
}

int main() {
    char q[MAX];
    int len;
    printf("Enter length of character queue: ");
    scanf("%d", &len);
    printf("Enter %d characters separated by space: ", len);
    for (int i = 0; i < len; i++) {
        scanf(" %c", &q[i]);
    }
    if (isQueuePalindrome(q, len))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

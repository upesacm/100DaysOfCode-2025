
#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeKdigits(char *num, int k) {
    char stack[MAX];
    int top = -1, len = strlen(num);

    for (int i = 0; i < len; i++) {
        while (top >= 0 && stack[top] > num[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    // Remove remaining k digits from end
    top -= k;

    // Skip leading zeros
    int index = 0;
    while (index <= top && stack[index] == '0') index++;

    if (index > top)
        printf("0\n");
    else {
        stack[top + 1] = '\0';
        printf("Result: %s\n", stack + index);
    }
}

int main() {
    char num[MAX];
    int k;
    printf("Enter number: ");
    scanf("%s", num);
    printf("Enter k: ");
    scanf("%d", &k);
    removeKdigits(num, k);
    return 0;
}

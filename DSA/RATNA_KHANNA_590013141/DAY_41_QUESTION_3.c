#include <stdio.h>
#include <string.h>

#define MAX 10005

char* removeKdigits(char* num, int k) {
    static char stack[MAX];
    int top = -1;

    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        char c = num[i];
        while (top >= 0 && k > 0 && stack[top] > c) {
            top--;
            k--;
        }
        stack[++top] = c;
    }

    // Remove extra digits from the end if needed
    top -= k;

    // Skip leading zeros
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }

    // If nothing remains, return "0"
    if (start > top) return "0";

    // Null-terminate and return result
    stack[top + 1] = '\0';
    return &stack[start];
}

int main() {
    char num[MAX];
    int k;

    printf("Enter a non-negative number: ");
    scanf("%s", num);

    printf("Enter k (number of digits to remove): ");
    scanf("%d", &k);

    char *result = removeKdigits(num, k);
    printf("Smallest possible number after removing %d digits: %s\n", k, result);

    return 0;
}

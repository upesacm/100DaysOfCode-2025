#include <stdio.h>
#include <string.h>

#define MAX 10010

void removeKdigits(char *num, int k, char *result) {
    int len = strlen(num);
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = num[i];
        while (top >= 0 && stack[top] > c && k > 0) {
            top--;
            k--;
        }
        stack[++top] = c;
    }

    while (k > 0 && top >= 0) {
        top--;
        k--;
    }

    int idx = 0;
    int leadingZero = 1;

    for (int i = 0; i <= top; i++) {
        if (leadingZero && stack[i] == '0') continue;
        leadingZero = 0;
        result[idx++] = stack[i];
    }

    if (idx == 0) {
        strcpy(result, "0");
    } else {
        result[idx] = '\0';
    }
}

int main() {
    char num[MAX];
    int k;
    char result[MAX];

    printf("Enter number: ");
    scanf("%s", num);
    printf("Enter k: ");
    scanf("%d", &k);

    removeKdigits(num, k, result);
    printf("Smallest number after removing %d digits: %s\n", k, result);

    return 0;
}

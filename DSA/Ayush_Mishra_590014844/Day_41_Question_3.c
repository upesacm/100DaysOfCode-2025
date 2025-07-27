#include <stdio.h>
#include <string.h>

void removeKdigits(char* num, int k) {
    char stack[10001];
    int top = -1;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        while (k && top >= 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }
    top -= k;
    int i = 0;
    while (i <= top && stack[i] == '0') i++;
    if (i > top) printf("0\n");
    else {
        for (int j = i; j <= top; j++) printf("%c", stack[j]);
        printf("\n");
    }
}

int main() {
    char num[10001];
    int k;
    printf("Enter the number: ");
    scanf("%s", num);
    printf("Enter k: ");
    scanf("%d", &k);
    removeKdigits(num, k);
    return 0;
}

#include <stdio.h>
#include <string.h>

void removeKdigits(char *num, int k) {
    int len = strlen(num);
    char stack[len + 1];
    int top = -1;

    for (int i = 0; i < len; i++) {
        while (k > 0 && top >= 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    // Remove remaining k digits from end
    top -= k;
    stack[top + 1] = '\0';

    // Remove leading zeros
    int start = 0;
    while (stack[start] == '0' && start <= top) start++;

    if (start > top) {
        printf("0\n");
    } else {
        printf("%s\n", stack + start);
    }
}

int main() {
    printf("Output 1: ");
    removeKdigits("1432219", 3);  

    printf("Output 2: ");
    removeKdigits("10200", 1);     

    return 0;
}


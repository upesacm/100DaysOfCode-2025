#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }
    while (k > 0 && top >= 0) {
        top--;
        k--;
    }
    if (top == -1) {
        free(stack);
        return "0";
    }
    char* result = (char*)malloc((top + 2) * sizeof(char));
    int j = 0;
    for (int i = 0; i <= top; i++) {
        if (!(j == 0 && stack[i] == '0')) {
            result[j++] = stack[i];
        }
    }
    result[j] = '\0';
    free(stack);
    return j == 0 ? "0" : result;
}
int main() {
    char num1[] = "1432219";
    int k1 = 3;
    char* result1 = removeKdigits(num1, k1);
    printf("%s\n", result1);
    free(result1);
    char num2[] = "10200";
    int k2 = 1;
    char* result2 = removeKdigits(num2, k2);
    printf("%s\n", result2);
    free(result2);
    return 0;
}

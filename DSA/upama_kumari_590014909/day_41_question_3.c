#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] > num[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = num[i]; 
    }

    top -= k;
    if (top < -1) top = -1;

    stack[top + 1] = '\0'; 

    int i = 0;
    while (stack[i] == '0' && i <= top) i++;

    char* result = strdup(stack + i);
    if (strlen(result) == 0)
        return strdup("0");

    return result;
}

int main() {
    char num[] = "10200";
    int k = 1;
    char* smallest = removeKdigits(num, k);
    printf("Output: %s\n", smallest); 
    free(smallest);
    return 0;
}

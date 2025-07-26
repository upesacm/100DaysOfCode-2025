#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k >= len) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }

    char* result_stack = (char*)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        while (top != -1 && k > 0 && result_stack[top] > num[i]) {
            top--;
            k--;
        }
        result_stack[++top] = num[i];
    }

    top -= k;

    result_stack[++top] = '\0';

    int start_index = 0;
    while (result_stack[start_index] == '0' && start_index < top - 1) {
        start_index++;
    }

    char* final_result = strdup(result_stack + start_index);
    free(result_stack);
    return final_result;
}

int main() {
    char s1[] = "1432219";
    char* r1 = removeKdigits(s1, 3);
    printf("Input: num = \"%s\", k = 3\nOutput: \"%s\"\n", s1, r1);
    free(r1);


    char s2[] = "10200";
    char* r2 = removeKdigits(s2, 1);
    printf("Input: num = \"%s\", k = 1\nOutput: \"%s\"\n", s2, r2);
    free(r2);

    return 0;
}
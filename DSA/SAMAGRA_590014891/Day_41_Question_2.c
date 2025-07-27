#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    char str_stack[10001][10001];
    int count_stack[10001];
    int top = -1, count = 0, i = 0;
    char res[10001] = "";

    while (s[i]) {
        if (isdigit(s[i])) {
            count = count * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            count_stack[++top] = count;
            strcpy(str_stack[top], res);
            res[0] = '\0';
            count = 0;
        } else if (s[i] == ']') {
            char temp[10001] = "";
            for (int j = 0; j < count_stack[top]; j++) strcat(temp, res);
            strcat(str_stack[top], temp);
            strcpy(res, str_stack[top--]);
        } else {
            int len = strlen(res);
            res[len] = s[i];
            res[len + 1] = '\0';
        }
        i++;
    }

    char* result = malloc(strlen(res) + 1);
    strcpy(result, res);
    return result;
}

int main() {
    char s[10001];
    scanf("%s", s);
    char* decoded = decodeString(s);
    printf("%s\n", decoded);
    free(decoded);
    return 0;
}

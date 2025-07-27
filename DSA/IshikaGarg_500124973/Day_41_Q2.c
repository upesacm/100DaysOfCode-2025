#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char* decodeString(const char* s) {
    char *stack[MAX], *result = malloc(MAX);
    int countStack[MAX];
    int top = -1, countTop = -1;
    int i = 0;
    char temp[MAX];
    strcpy(result, "");
    
    while (s[i]) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            countStack[++countTop] = num;
        } else if (s[i] == '[') {
            stack[++top] = strdup(result);
            strcpy(result, "");
            i++;
        } else if (s[i] == ']') {
            int repeat = countStack[countTop--];
            char* last = stack[top--];
            temp[0] = '\0';
            for (int j = 0; j < repeat; j++) {
                strcat(temp, result);
            }
            strcat(last, temp);
            strcpy(result, last);
            free(last);
            i++;
        } else {
            int len = strlen(result);
            result[len] = s[i++];
            result[len + 1] = '\0';
        }
    }

    return result;
}

int main() {
    printf("Output 1: %s\n", decodeString("3[a]2[bc]"));         
    printf("Output 2: %s\n", decodeString("2[abc]3[cd]ef"));
    return 0;
}


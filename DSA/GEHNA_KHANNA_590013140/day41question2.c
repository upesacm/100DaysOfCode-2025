#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void pushInt(IntStack *s, int val) {
    s->data[++(s->top)] = val;
}

int popInt(IntStack *s) {
    return s->data[(s->top)--];
}

typedef struct {
    char *data[MAX];
    int top;
} StrStack;

void pushStr(StrStack *s, const char *str) {
    s->data[++(s->top)] = strdup(str);
}

char* popStr(StrStack *s) {
    return s->data[(s->top)--];
}

char* decodeString(const char *s) {
    IntStack countStack = {.top = -1};
    StrStack strStack = {.top = -1};
    char currStr[MAX] = "";
    int i = 0, n = strlen(s);

    while (i < n) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            pushInt(&countStack, num);
        } else if (s[i] == '[') {
            pushStr(&strStack, currStr);
            currStr[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int repeat = popInt(&countStack);
            char *prev = popStr(&strStack);
            char temp[MAX] = "";
            for (int j = 0; j < repeat; j++) {
                strcat(temp, currStr);
            }
            strcpy(currStr, prev);
            strcat(currStr, temp);
            free(prev);
            i++;
        } else {
            int len = strlen(currStr);
            currStr[len] = s[i];
            currStr[len + 1] = '\0';
            i++;
        }
    }

    return strdup(currStr);
}

int main() {
    char input[MAX];
    printf("Enter encoded string: ");
    scanf("%s", input);

    char *result = decodeString(input);
    printf("Decoded string: %s\n", result);
    free(result);

    return 0;
}

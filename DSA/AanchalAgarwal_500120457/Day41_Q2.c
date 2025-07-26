#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Stack structure for strings
typedef struct {
    char *data[MAX];
    int top;
} StringStack;

// Stack structure for integers
typedef struct {
    int data[MAX];
    int top;
} IntStack;

// Stack functions
void pushString(StringStack *s, const char *str) {
    s->data[++(s->top)] = strdup(str);
}

char *popString(StringStack *s) {
    return s->data[(s->top)--];
}

void pushInt(IntStack *s, int val) {
    s->data[++(s->top)] = val;
}

int popInt(IntStack *s) {
    return s->data[(s->top)--];
}

// Decoder function
char* decodeString(const char *s) {
    StringStack strStack = {.top = -1};
    IntStack numStack = {.top = -1};
    char current[MAX] = "";
    int i = 0, n = strlen(s);

    while (i < n) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i++] - '0');
            }
            pushInt(&numStack, num);
        } else if (s[i] == '[') {
            pushString(&strStack, current);
            current[0] = '\0';  // reset current string
            i++;
        } else if (s[i] == ']') {
            char *prev = popString(&strStack);
            int count = popInt(&numStack);

            char temp[MAX] = "";
            for (int j = 0; j < count; j++) {
                strcat(temp, current);
            }

            strcpy(current, prev);
            strcat(current, temp);
            free(prev);
            i++;
        } else {
            int len = strlen(current);
            current[len] = s[i++];
            current[len + 1] = '\0';
        }
    }

    return strdup(current);
}

// Driver code
int main() {
    char input1[] = "3[a]2[bc]";
    char input2[] = "2[abc]3[cd]ef";

    char *output1 = decodeString(input1);
    printf("Output 1: %s\n", output1);  // "aaabcbc"

    char *output2 = decodeString(input2);
    printf("Output 2: %s\n", output2);  // "abcabccdcdcdef"

    free(output1);
    free(output2);
    return 0;
}


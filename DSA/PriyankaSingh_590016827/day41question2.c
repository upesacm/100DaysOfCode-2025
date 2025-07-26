
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char *decodeString(char *s) {
    char strStack[MAX][MAX];
    int numStack[MAX];
    int strTop = -1, numTop = -1;
    char currStr[MAX] = "";
    int k = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack[++numTop] = k;
            strcpy(strStack[++strTop], currStr);
            currStr[0] = '\0';
            k = 0;
        } else if (s[i] == ']') {
            int repeat = numStack[numTop--];
            char temp[MAX] = "";
            for (int j = 0; j < repeat; j++)
                strcat(temp, currStr);
            strcpy(currStr, strStack[strTop--]);
            strcat(currStr, temp);
        } else {
            int len = strlen(currStr);
            currStr[len] = s[i];
            currStr[len + 1] = '\0';
        }
    }

    char *result = (char *)malloc(strlen(currStr) + 1);
    strcpy(result, currStr);
    return result;
}

int main() {
    char input[MAX];
    printf("Enter encoded string: ");
    scanf("%s", input);
    char *decoded = decodeString(input);
    printf("Decoded: %s\n", decoded);
    free(decoded);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char* decodeString(char* s) {
    char *strStack[MAX], *numStack[MAX];
    int topStr = -1, topNum = -1;

    char currStr[MAX] = "";
    int i = 0;

    while (s[i]) {
        if (isdigit(s[i])) {
            char num[10] = "";
            while (isdigit(s[i]))
                strncat(num, &s[i++], 1);
            numStack[++topNum] = strdup(num);
        } else if (s[i] == '[') {
            strStack[++topStr] = strdup(currStr);
            currStr[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int repeat = atoi(numStack[topNum--]);
            char temp[MAX] = "";
            for (int j = 0; j < repeat; j++)
                strcat(temp, currStr);
            strcpy(currStr, strStack[topStr--]);
            strcat(currStr, temp);
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
    char input[] = "3[a]2[bc]";
    char* decoded = decodeString(input);
    printf("Decoded: %s\n", decoded);
    free(decoded);
    return 0;
}

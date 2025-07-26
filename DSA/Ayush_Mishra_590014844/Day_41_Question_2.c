#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    char strStack[1000][1000];
    int strTop = -1;
    int countStack[1000], countTop = -1;
    char temp[1000], res[1000] = "";
    int i = 0;

    while (s[i]) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            countStack[++countTop] = num;
        } else if (s[i] == '[') {
            strTop++;
            strcpy(strStack[strTop], res);
            res[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            strcpy(temp, strStack[strTop--]);
            int times = countStack[countTop--];
            for (int j = 0; j < times; j++) strcat(temp, res);
            strcpy(res, temp);
            i++;
        } else {
            int len = strlen(res);
            res[len] = s[i++];
            res[len + 1] = '\0';
        }
    }
    return strdup(res);
}

int main() {
    char input[1000];
    printf("Enter the encoded string: ");
    scanf("%s", input);
    char* result = decodeString(input);
    printf("%s\n", result);
    free(result);
    return 0;
}

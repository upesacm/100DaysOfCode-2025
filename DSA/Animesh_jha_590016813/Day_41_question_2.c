#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void repeat(char *dest, const char *str, int count) {
    dest[0] = '\0';  
    for (int i = 0; i < count; i++) {
        strcat(dest, str);
    }
}

char* decodeString(const char* s) {
    char* result = (char*)malloc(MAX * sizeof(char));
    char* currStr = (char*)malloc(MAX * sizeof(char));
    int countStack[MAX];
    char strStack[MAX][MAX];
    int countTop = -1, strTop = -1;

    int i = 0, len = strlen(s);
    currStr[0] = '\0';

    while (i < len) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            countStack[++countTop] = num;  
        } else if (s[i] == '[') {
            strcpy(strStack[++strTop], currStr);  
            currStr[0] = '\0';  
            i++;
        } else if (s[i] == ']') {
            int repeatCount = countStack[countTop--];
            char temp[MAX];
            repeat(temp, currStr, repeatCount);

            strcat(strStack[strTop], temp);  
            strcpy(currStr, strStack[strTop--]); 
            i++;
        } else {
            int len = strlen(currStr);
            currStr[len] = s[i];
            currStr[len + 1] = '\0';
            i++;
        }
    }

    strcpy(result, currStr);
    free(currStr);
    return result;
}

int main() {
    const char* input = "3[a]2[bc]";
    char* output = decodeString(input);
    printf("Output: %s\n", output);  
    free(output);
    return 0;
}

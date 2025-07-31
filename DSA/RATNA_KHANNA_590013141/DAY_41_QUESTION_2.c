#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
int countStack[MAX], countTop = -1;
char *stringStack[MAX];
int stringTop = -1;
void pushCount(int val) {
    countStack[++countTop] = val;
}
int popCount() {
    return countStack[countTop--];
}
void pushString(char *str) {
    stringStack[++stringTop] = strdup(str);
}
char* popString() {
    return stringStack[stringTop--];
}
char* decodeString(char *s) {
    char currStr[MAX] = "";
    int i = 0, n = strlen(s);

    while (i < n) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i]))
                num = num * 10 + (s[i++] - '0');
            pushCount(num);
        } else if (s[i] == '[') {
            pushString(currStr);
            currStr[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int count = popCount();
            char *prevStr = popString();
            char temp[MAX] = "";
            for (int j = 0; j < count; j++)
                strcat(temp, currStr);
            strcpy(currStr, prevStr);
            strcat(currStr, temp);
            free(prevStr);
            i++;
        } else {
            int len = strlen(currStr);
            currStr[len] = s[i++];
            currStr[len + 1] = '\0';
        }
    }

    return strdup(currStr);
}

int main() {
    char input[MAX];
    
    printf("Enter an encoded string: ");
    scanf("%s", input);  
    char *decoded = decodeString(input);
    printf("Decoded string: %s\n", decoded);
    free(decoded);
    return 0;
}

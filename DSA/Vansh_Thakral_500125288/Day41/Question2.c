#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void decodeString(char *s) {
    char strStack[MAX][MAX], temp[MAX], res[MAX] = "";
    int numStack[MAX], topStr = -1, topNum = -1, i = 0;

    while (s[i]) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) num = num * 10 + (s[i++] - '0');
            numStack[++topNum] = num;
        } else if (s[i] == '[') {
            strStack[++topStr][0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int count = numStack[topNum--];
            strcpy(temp, strStack[topStr--]);
            char expanded[MAX] = "";
            while (count--) strcat(expanded, temp);
            if (topStr >= 0)
                strcat(strStack[topStr], expanded);
            else
                strcat(res, expanded);
            i++;
        } else {
            if (topStr >= 0) {
                int len = strlen(strStack[topStr]);
                strStack[topStr][len++] = s[i++];
                strStack[topStr][len] = '\0';
            } else {
                int len = strlen(res);
                res[len++] = s[i++];
                res[len] = '\0';
            }
        }
    }

    printf("Output: %s\n", res);
}


int main() {
    decodeString("3[a]2[bc]");        
    decodeString("2[abc]3[cd]ef");    
    return 0;
}


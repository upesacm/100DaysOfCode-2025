#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void decodeString(char *s, char *result) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    char numStack[len];
    int numTop = -1;
    int i = 0, j = 0;
    while (i < len) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numStack[++numTop] = num;
        } else if (s[i] == '[') {
            stack[++top] = '\0';
            i++;
        } else if (s[i] == ']') {
            char temp[1000];
            int k = numStack[numTop--];
            int length = 0;
            while (top >= 0 && stack[top] != '\0') {
                temp[length++] = stack[top--];
            }
            temp[length] = '\0';
            for (int repeat = 0; repeat < k; repeat++) {
                for (int t = length - 1; t >= 0; t--) {
                    stack[++top] = temp[t];
                }
            }
            i++;
        } else {
            stack[++top] = s[i++];
        }
    }
    while (top >= 0) {
        result[j++] = stack[top--];
    }
    result[j] = '\0';
    strrev(result);
}
int main() {
    char str1[] = "3[a]2[bc]";
    char result1[1000];
    decodeString(str1, result1);
    printf("%s\n", result1);
    char str2[] = "2[abc]3[cd]ef";
    char result2[1000];
    decodeString(str2, result2);
    printf("%s\n", result2);
    return 0;
}

// 2. Decode a String
// A problem that introduces nested structure parsing and teaches stack-based decoding algorithms for handling recursive string expansion with numerical multipliers and bracket notation.

// Given an encoded string like "3[a]2[bc]", decode it using a stack where the pattern k[substring] means the substring inside brackets is repeated k times. This operation is fundamental in data decompression and template expansion where you need to process nested repetition patterns with variable multipliers. The technique uses dual stack management to track both numerical multipliers and string fragments, enabling recursive expansion of nested patterns. This concept is essential in configuration parsing, template engines, and markup processing where structured text expansion requires systematic bracket matching and content multiplication.

// This introduces nested parsing algorithms and recursive string expansion techniques that are crucial for template processing and structured text decoding operations.

// Your task: Implement dual-stack parsing to handle nested bracket structures with numerical multipliers for accurate recursive string expansion.

// Examples
// Input:

// "3[a]2[bc]"
// Output:

// "aaabcbc"
// Input:

// "2[abc]3[cd]ef"
// Output:

// "abcabccdcdcdef"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
typedef struct {
    char* data[MAX];
    int top;
} StackStr;
typedef struct {
    int data[MAX];
    int top;
} StackInt;
void pushStr(StackStr* stack, char* str) {
    stack->data[++(stack->top)] = strdup(str);
}
char* popStr(StackStr* stack) {
    if (stack->top == -1) return "";
    return stack->data[(stack->top)--];
}
void pushInt(StackInt* stack, int val) {
    stack->data[++(stack->top)] = val;
}
int popInt(StackInt* stack) {
    if (stack->top == -1) return 0;
    return stack->data[(stack->top)--];
}
char* decodeString(char* s) {
    StackStr strStack;
    StackInt numStack;
    strStack.top = -1;
    numStack.top = -1;
    char* curr = (char*)malloc(MAX);
    curr[0] = '\0';
    int i = 0;
    while (s[i]) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            pushInt(&numStack, num);
        } else if (s[i] == '[') {
            pushStr(&strStack, curr);
            curr = (char*)malloc(MAX);
            curr[0] = '\0';
            i++;
        } else if (s[i] == ']') {
            int repeat = popInt(&numStack);
            char* prev = popStr(&strStack);
            char* temp = (char*)malloc(MAX);
            temp[0] = '\0';
            for (int r = 0; r < repeat; r++) {
                strcat(temp, curr);
            }
            strcat(prev, temp);
            free(curr);
            curr = prev;
            i++;
        } else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
            i++;
        }
    }
    return curr;
}
// 1. Remove Adjacent Duplicates from String
// A problem that demonstrates string processing techniques and teaches iterative duplicate elimination using stack-based character tracking for text cleaning and optimization operations.

// Given a string, remove all adjacent duplicates using a stack and repeat the process until no adjacent duplicates are left. This operation is fundamental in text processing and string optimization where you need to eliminate redundant patterns iteratively until a stable state is reached. The technique uses a stack-based comparison to detect and remove consecutive identical characters, requiring multiple passes until no further reductions are possible. Understanding this concept is crucial for data compression, text normalization, and string simplification algorithms where removing redundant sequences improves storage efficiency and processing performance.

// This teaches iterative string reduction algorithms and stack-based pattern elimination techniques that are essential for text processing and efficient string optimization operations.

// Your task: Use a stack to systematically remove adjacent duplicate characters through iterative elimination until achieving a stable reduced string.

// Examples
// Input:

// "abbaca"
// Output:

// "ca"
// Input:

// "azxxzy"
// Output:

// "ay"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *removeDuplicates(char* s){
    int len=strlen(s);
    char* result_stack = (char*)malloc(len + 1); 
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (top != -1 && result_stack[top] == s[i]) {
            top--;
        } else {
            result_stack[++top] = s[i];
        }
    }
    result_stack[++top] = '\0';
    return result_stack;
}

int main(){
    char s1[]="abbaca";
    char* r1 = removeDuplicates(s1);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s1, r1);
    free(r1);

    char s2[]="azxxzy"; 
    char* r2 = removeDuplicates(s2);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s2, r2);
    free(r2);
    
    return 0;
}
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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 1000
#define MAX_BUFFER_SIZE 10000

char* decodeString(char *s){
    int len=strlen(s);
    int countStack[MAX_STACK_SIZE];
    int indexStack[MAX_STACK_SIZE];
    int countTop=-1;
    int indexTop=-1;

    char *result=(char*)malloc(MAX_BUFFER_SIZE);
    int resultIndex=0;
    int k=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9') k=k*10+(s[i]-'0');
        else if(s[i]=='[') {
            countStack[++countTop]=k;
            indexStack[++indexTop]=resultIndex;
            k=0;
        }else if(s[i]==']'){
            int count=countStack[countTop--];
            int startIndex = indexStack[indexTop--];
            int subLen = resultIndex - startIndex;

            for (int j = 0; j < count - 1; j++) {
                memcpy(result + resultIndex, result + startIndex, subLen);
                resultIndex += subLen;
            }
        } else {
            result[resultIndex++] = s[i];
        }
    }

    result[resultIndex] = '\0';
    return result;
}


int main() {
    char s1[] = "3[a]2[bc]";
    char* r1 = decodeString(s1);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s1, r1);
    free(r1);


    char s2[] = "2[abc]3[cd]ef";
    char* r2 = decodeString(s2);
    printf("Input: \"%s\"\nOutput: \"%s\"\n\n", s2, r2);
    free(r2);

    return 0;
}
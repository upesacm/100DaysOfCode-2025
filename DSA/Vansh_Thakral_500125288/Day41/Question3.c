#include <stdio.h>
#include <string.h>

void removeKdigits(char *num, int k) {
    char stack[strlen(num)];
    int top = -1;

    for (int i = 0; num[i]; i++) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

   
    top -= k;
    stack[top + 1] = '\0';


    int start = 0;
    while (stack[start] == '0') start++;

    if (start > top)
        printf("Output: 0\n");
    else
        printf("Output: %s\n", stack + start);
}


int main() {
    removeKdigits("1432219", 3);  
    removeKdigits("10200", 1);    
    return 0;
}


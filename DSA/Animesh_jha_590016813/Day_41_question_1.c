#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char* str) {
    int n = strlen(str);
    if (n == 0) return;

    char stack[n];  
    int top = -1;  

    for (int i = 0; i < n; i++) {
        if (top >= 0 && stack[top] == str[i]) {
            top--;
        } else {
            stack[++top] = str[i];
        }
    }

    stack[top + 1] = '\0';  
    strcpy(str, stack);   
}

int main() {
    char str[] = "abbaca";
    removeAdjacentDuplicates(str);
    printf("Output: %s\n", str); 
    return 0;
}

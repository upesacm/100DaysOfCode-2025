#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeAdjacentDuplicates(char *str) {
    int changed;

    do {
        changed = 0;
        char stack[MAX];
        int top = -1;

        for (int i = 0; str[i] != '\0'; i++) {
            if (top != -1 && stack[top] == str[i]) {
                top--;         
                changed = 1;   
            } else {
                stack[++top] = str[i];  
            }
        }

        stack[++top] = '\0';       
        strcpy(str, stack);        

    } while (changed);  
}

int main() {
    char input[MAX];

    printf("Enter a string: ");
    scanf("%s", input);  
    removeAdjacentDuplicates(input);

    printf("Result: %s\n", input);
    return 0;
}

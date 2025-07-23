#include <stdio.h>

int main() {
    char s[1000], stack[1000];
    int top = -1;

    printf("Enter expression: ");
    scanf("%s", s);

    int balanced = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            top++;
            stack[top] = s[i];
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top == -1) {
                balanced = 0;
                break;
            }
            char open = stack[top];
            if ((s[i] == ')' && open != '(') ||
                (s[i] == ']' && open != '[') ||
                (s[i] == '}' && open != '{')) {
                balanced = 0;
                break;
            }
            top--;
        }
    }

    if (top != -1) balanced = 0;

    if (balanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}

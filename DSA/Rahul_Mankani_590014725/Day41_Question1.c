#include <stdio.h>
#include <string.h>

#define MAX 1000
void remove(char* str) 
{
    char s[MAX];
    int top = -1;
    for(int i = 0; str[i]; i++) 
    {
        if(top >= 0 && s[top] == str[i]) 
        {
            top--;
        } 
        else 
        {
            s[++top] = str[i];
        }
    }
    s[top + 1] = '\0';
    strcpy(str, s);
}
int main() 
{
    char str[MAX];
    scanf("%s", str);
    remove(str);
    printf("%s\n", str);
    return 0;
}

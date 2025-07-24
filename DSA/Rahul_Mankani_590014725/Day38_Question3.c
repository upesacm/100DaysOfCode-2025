#include <stdio.h>
#include <string.h>

#define MAX 1000
int Redundant(char* exp) 
{
    char s[MAX];
    int top = -1;
    for(int i = 0; exp[i]; i++) 
    {
        if(exp[i] == ')') 
        {
            int hasOp = 0;
            while(top >= 0 && s[top] != '(') 
            {
                if(s[top] == '+' || s[top] == '-' || s[top] == '*' || s[top] == '/') 
                {
                    hasOp = 1;
                }
                top--;
            }
            if(top >= 0) top--;
            if(!hasOp) return 1;
        } 
        else 
        {
            s[++top] = exp[i];
        }
    }
    return 0;
}
int main() 
{
    char exp[MAX];
    scanf("%s", exp);
    printf("%s\n", Redundant(exp) ? "Yes" : "No");
    return 0;
}

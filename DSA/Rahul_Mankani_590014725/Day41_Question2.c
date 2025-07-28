#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
typedef struct 
{
    char s[MAX][MAX];
    int n[MAX], top;
} Stack;
void pushStr(Stack* st, char* str) 
{
    strcpy(st->s[++st->top], str);
}
void pushNum(Stack* st, int num) 
{
    st->n[st->top] = num;
}
char* popStr(Stack* st) 
{
    return st->s[st->top--];
}
int popNum(Stack* st) 
{
    return st->n[st->top];
}
char* decode(char* str) 
{
    Stack st;
    st.top = -1;
    char* res = (char*)malloc(MAX * sizeof(char));
    char curr[MAX] = "", numStr[MAX] = "";
    int num = 0, j = 0;
    for(int i = 0; str[i]; i++) 
    {
        if(str[i] >= '0' && str[i] <= '9') 
        {
            numStr[j++] = str[i];
        } 
        else if(str[i] == '[') 
        {
            numStr[j] = '\0';
            pushNum(&st, atoi(numStr));
            pushStr(&st, curr);
            j = 0;
            curr[0] = '\0';
        } 
        else if(str[i] == ']') 
        {
            char temp[MAX] = "", newStr[MAX] = "";
            int k = popNum(&st);
            strcpy(temp, curr);
            strcpy(curr, popStr(&st));
            for(int m = 0; m < k; m++) 
            {
                strcat(newStr, temp);
            }
            strcat(curr, newStr);
        } 
        else 
        {
            int len = strlen(curr);
            curr[len] = str[i];
            curr[len + 1] = '\0';
        }
    }
    strcpy(res, curr);
    return res;
}
int main() 
{
    char str[MAX];
    scanf("%s", str);
    char* result = decode(str);
    printf("%s\n", result);
    free(result);
    return 0;
}

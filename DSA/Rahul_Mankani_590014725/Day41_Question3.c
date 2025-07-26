#include <stdio.h>
#include <string.h>

#define MAX 100001
char* remove(char* num, int k) 
{
    char s[MAX];
    int top = -1, n = strlen(num);
    for(int i = 0; i < n; i++) 
    {
        while(top >= 0 && k > 0 && s[top] > num[i]) 
        {
            top--;
            k--;
        }
        s[++top] = num[i];
    }
    while(k > 0 && top >= 0) 
    {
        top--;
        k--;
    }
    int start = 0;
    while(start <= top && s[start] == '0') start++;
    if(start > top) return "0";
    s[top + 1] = '\0';
    return strdup(&s[start]);
}
int main() 
{
    char num[MAX];
    int k;
    scanf("%s %d", num, &k);
    char* result = remove(num, k);
    printf("%s\n", result);
    free(result);
    return 0;
}

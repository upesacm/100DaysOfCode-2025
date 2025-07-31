#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char *decodeString(const char *s)
{
    char *strStack[MAX], result[MAX] = "";
    int numStack[MAX], strTop = -1, numTop = -1;
    int i = 0, n = strlen(s);
    char temp[MAX], ch[2];

    while (i < n)
    {
        if (isdigit(s[i]))
        {
            int num = 0;
            while (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numStack[++numTop] = num;
        }
        else if (s[i] == '[')
        {
            strStack[++strTop] = strdup(result);
            result[0] = '\0';
            i++;
        }
        else if (s[i] == ']')
        {
            int count = numStack[numTop--];
            char *prev = strStack[strTop--];
            strcpy(temp, prev);
            for (int j = 0; j < count; j++)
                strcat(temp, result);
            strcpy(result, temp);
            free(prev);
            i++;
        }
        else
        {
            ch[0] = s[i];
            ch[1] = '\0';
            strcat(result, ch);
            i++;
        }
    }

    return strdup(result);
}

int main()
{
    char *output1 = decodeString("3[a]2[bc]");
    char *output2 = decodeString("2[abc]3[cd]ef");

    printf("Decoded: %s\n", output1); // aaabcbc
    printf("Decoded: %s\n", output2); // abcabccdcdcdef

    free(output1);
    free(output2);

    return 0;
}

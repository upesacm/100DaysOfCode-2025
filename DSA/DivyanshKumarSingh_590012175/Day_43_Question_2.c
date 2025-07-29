#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char *queue[MAX];
int front, rear;

void enqueue(char *str)
{
    queue[rear++] = strdup(str); 
}

char *dequeue()
{
    if (front == rear)
        return NULL;
    return queue[front++];
}

void generateBinary(int n)
{

    front = 0;
    rear = 0;

    enqueue("1");

    printf("Binary numbers from 1 to %d:\n", n);
    for (int i = 1; i <= n; i++)
    {
        char *s = dequeue();
        if (!s)
            break;

        printf("%s ", s);

        char s0[MAX], s1[MAX];
        strcpy(s0, s);
        strcat(s0, "0");
        strcpy(s1, s);
        strcat(s1, "1");

        enqueue(s0);
        enqueue(s1);

        free(s); 
    }
    printf("\n");

    while (front < rear)
    {
        free(queue[front++]);
    }
}

int main()
{
    generateBinary(5);
    generateBinary(3);
    return 0;
}

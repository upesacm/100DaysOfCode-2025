#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void push(char stack[], int *top, char ch) 
{
    stack[++(*top)] = ch;
}
char pop(char stack[], int *top) 
{
    return stack[(*top)--];
}
void enqueue(char queue[], int *rear, char ch) 
{
    queue[++(*rear)] = ch;
}
char dequeue(char queue[], int *front) 
{
    return queue[(*front)++];
}
int main() 
{
    char queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;
    char input[MAX];
    printf("Enter a sequence of characters (no spaces): ");
    scanf("%s", input);
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        enqueue(queue, &rear, input[i]);
        push(stack, &top, input[i]);
    }
    int isPalindrome = 1;
    while (front <= rear) 
    {
        char fromQueue = dequeue(queue, &front);
        char fromStack = pop(stack, &top);
        if (fromQueue != fromStack)
        {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The sequence is a palindrome.\n");
    else
        printf("The sequence is NOT a palindrome.\n");
    return 0;
}

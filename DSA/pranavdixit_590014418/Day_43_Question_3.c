#include <stdio.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = -1;

void enqueue(char c) {
    queue[++rear] = c;
}

int isPalindrome() {
    char stack[MAX];
    int top = -1;

    for (int i = front; i <= rear; i++)
        stack[++top] = queue[i];

    for (int i = front; i <= rear; i++) {
        if (queue[i] != stack[top--])
            return 0;
    }
    return 1;
}

int main() {
    enqueue('r');
    enqueue('a');
    enqueue('c');
    enqueue('e');
    enqueue('c');
    enqueue('a');
    enqueue('r');

    if (isPalindrome())
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

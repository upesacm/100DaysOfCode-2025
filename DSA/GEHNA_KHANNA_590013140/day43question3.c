#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = 0;

char stack[MAX];
int top = -1;

void enqueue(char ch) {
    queue[rear++] = ch;
}

char dequeue() {
    return queue[front++];
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isPalindrome() {
    for (int i = front; i < rear; i++) {
        push(queue[i]);
    }
    for (int i = front; i < rear; i++) {
        if (queue[i] != pop())
            return 0;
    }
    return 1;
}

int main() {
    int n;
    char ch;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);
        enqueue(ch);
    }
    if (isPalindrome())
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = -1;

void enqueue(char c) {
    queue[++rear] = c;
}

char dequeue() {
    return queue[front++];
}

int main() {
    int i, n;
    char ch, stack[MAX];
    int top = -1, isPalindrome = 1;

    printf("Enter number of characters in queue: ");
    scanf("%d", &n);

    printf("Enter characters: ");
    for (i = 0; i < n; i++) {
        scanf(" %c", &ch);
        enqueue(ch);
        stack[++top] = ch;
    }

    for (i = 0; i < n; i++) {
        if (dequeue() != stack[top--]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) printf("Yes\n");
    else printf("No\n");

    return 0;
}

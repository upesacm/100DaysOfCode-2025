#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX], stack[MAX];
int front = 0, rear = -1, top = -1;

void enqueue(char ch) {
    queue[++rear] = ch;
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

int main() {
    char input[MAX];
    scanf("%s", input);
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        enqueue(input[i]);
        push(input[i]);
    }

    int isPalindrome = 1;
    for (int i = 0; i < len; i++) {
        if (dequeue() != pop()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char* queue[MAX];
int front = 0, rear = -1;

void enqueue(char* str) {
    queue[++rear] = strdup(str);
}

char* dequeue() {
    return queue[front++];
}

void generateBinary(int n) {
    enqueue("1");

    for (int i = 0; i < n; i++) {
        char* s = dequeue();
        printf("%s ", s);

        char s0[MAX], s1[MAX];
        sprintf(s0, "%s0", s);
        sprintf(s1, "%s1", s);

        enqueue(s0);
        enqueue(s1);

        free(s);
    }
    printf("\n");
}

int main() {
    int n = 5;
    generateBinary(n);
    return 0;
}

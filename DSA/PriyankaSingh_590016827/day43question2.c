#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char *data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, char *val) {
    q->data[q->rear++] = strdup(val);
}

char* dequeue(Queue *q) {
    return q->data[q->front++];
}

void generateBinary(int n) {
    Queue q = {.front = 0, .rear = 0};
    enqueue(&q, "1");

    for (int i = 1; i <= n; i++) {
        char *s = dequeue(&q);
        printf("%s ", s);

        char s0[SIZE], s1[SIZE];
        sprintf(s0, "%s0", s);
        sprintf(s1, "%s1", s);

        enqueue(&q, s0);
        enqueue(&q, s1);

        free(s);
    }
    printf("\n");
}

int main() {
    int n = 5;
    generateBinary(n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, char *str) {
    strcpy(q->data[q->rear++], str);
}

char* dequeue(Queue *q) {
    return q->data[q->front++];
}

void generateBinary(int n) {
    Queue q = {.front = 0, .rear = 0};
    enqueue(&q, "1");

    for (int i = 0; i < n; i++) {
        char *temp = dequeue(&q);
        printf("%s ", temp);

        char temp0[MAX], temp1[MAX];
        sprintf(temp0, "%s0", temp);
        sprintf(temp1, "%s1", temp);

        enqueue(&q, temp0);
        enqueue(&q, temp1);
    }
    printf("\n");
}

int main() {
    int n = 5;
    generateBinary(n);
    return 0;
}

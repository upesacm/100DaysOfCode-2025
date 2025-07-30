#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, const char *data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->data, data);
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

char* dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;
    struct Node *temp = q->front;
    char *data = (char *)malloc(100);
    strcpy(data, temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void generateBinary(int n) {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, "1");

    for (int i = 0; i < n; i++) {
        char *current = dequeue(&q);
        printf("%s ", current);

        char zero[100], one[100];
        strcpy(zero, current);
        strcat(zero, "0");
        strcpy(one, current);
        strcat(one, "1");

        enqueue(&q, zero);
        enqueue(&q, one);

        free(current);
    }
}

int main() {
    int n = 5;
    printf("Binary numbers from 1 to %d:\n", n);
    generateBinary(n);
    return 0;
}

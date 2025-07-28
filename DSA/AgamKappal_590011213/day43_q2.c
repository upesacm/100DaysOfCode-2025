#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char val[20];
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue *q, char *val) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    strcpy(temp->val, val);
    temp->next = NULL;
    if (q->rear == NULL) q->front = q->rear = temp;
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

char* dequeue(struct Queue *q) {
    if (q->front == NULL) return NULL;
    struct Node *temp = q->front;
    char *val = (char *)malloc(20);
    strcpy(val, temp->val);
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void generateBinary(int n) {
    struct Queue q;
    q.front = q.rear = NULL;
    enqueue(&q, "1");
    for (int i = 0; i < n; i++) {
        char *s = dequeue(&q);
        printf("%s ", s);
        char s0[20], s1[20];
        strcpy(s0, s);
        strcpy(s1, s);
        strcat(s0, "0");
        strcat(s1, "1");
        enqueue(&q, s0);
        enqueue(&q, s1);
        free(s);
    }
    printf("\n");
}

int main() {
    generateBinary(5);
    return 0;
}
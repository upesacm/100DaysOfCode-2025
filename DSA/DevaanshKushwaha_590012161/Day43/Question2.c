#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
    char* data;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

QNode* newQNode(char* k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = strdup(k);
    temp->next = NULL;
    return temp;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, char* k) {
    QNode* temp = newQNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

char* deQueue(Queue* q) {
    if (q->front == NULL) return NULL;
    QNode* temp = q->front;
    char* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue* q = createQueue();
    enQueue(q, "1");

    for (int i = 0; i < n; i++) {
        char* current = deQueue(q);
        printf("%s ", current);

        char* s1 = (char*)malloc(strlen(current) + 2);
        strcpy(s1, current);
        strcat(s1, "0");
        enQueue(q, s1);
        free(s1);

        char* s2 = (char*)malloc(strlen(current) + 2);
        strcpy(s2, current);
        strcat(s2, "1");
        enQueue(q, s2);
        free(s2);

        free(current);
    }
    printf("\n");

    while (q->front != NULL) {
        free(deQueue(q));
    }
    free(q);

    return 0;
}

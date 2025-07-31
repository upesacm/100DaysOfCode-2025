#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

QNode* newQNode(int k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, int k) {
    QNode* temp = newQNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int deQueue(Queue* q) {
    if (q->front == NULL) return INT_MIN;
    QNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

int findMaxElementInQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        return INT_MIN;
    }
    int max_val = INT_MIN;
    QNode* current = q->front;
    while (current != NULL) {
        if (current->data > max_val) {
            max_val = current->data;
        }
        current = current->next;
    }
    return max_val;
}

int main() {
    Queue* q = createQueue();
    int numElements, value;

    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        scanf("%d", &value);
        enQueue(q, value);
    }

    printf("%d\n", findMaxElementInQueue(q));

    while (!isEmptyQueue(q)) {
        deQueue(q);
    }
    free(q);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
int areQueuesIdentical(Queue* q1, Queue* q2) {
    Queue* temp1 = createQueue();
    Queue* temp2 = createQueue();
    int identical = 1;
    while (q1->front != NULL && q2->front != NULL) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);
        enqueue(temp1, val1);
        enqueue(temp2, val2);
        if (val1 != val2) {
            identical = 0;
        }
    }
    if (q1->front != NULL || q2->front != NULL) {
        identical = 0;
    }
    while (temp1->front != NULL) {
        enqueue(q1, dequeue(temp1));
    }
    while (temp2->front != NULL) {
        enqueue(q2, dequeue(temp2));
    }
    free(temp1);
    free(temp2);
    return identical;
}
int main() {
    Queue* q1 = createQueue();
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    Queue* q2 = createQueue();
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 3);
    printf("%s\n", areQueuesIdentical(q1, q2) ? "Yes" : "No");
    Queue* q3 = createQueue();
    enqueue(q3, 1);
    enqueue(q3, 2);
    Queue* q4 = createQueue();
    enqueue(q4, 2);
    enqueue(q4, 1);
    printf("%s\n", areQueuesIdentical(q3, q4) ? "Yes" : "No");
    return 0;
}
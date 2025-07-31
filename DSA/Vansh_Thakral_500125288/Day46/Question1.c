#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int val) {
    if(q->rear < MAX-1)
        q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    if(!isEmpty(q))
        return q->arr[q->front++];
    return -1;
}

int findMin(Queue q) { 
    if(isEmpty(&q)) return -1;
    int minVal = q.arr[q.front];
    for(int i = q.front+1; i <= q.rear; i++) {
        if(q.arr[i] < minVal)
            minVal = q.arr[i];
    }
    return minVal;
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 1);

    printf("Minimum element: %d\n", findMin(q));
    return 0;
}


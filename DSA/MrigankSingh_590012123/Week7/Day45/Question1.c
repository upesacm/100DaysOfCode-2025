#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int is_empty_queue(Queue *q) {
    return q->size == 0;
}

int enqueue(Queue *q, int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return 0;
    new_node->data = x;
    new_node->next = NULL;
    if (is_empty_queue(q)) {
        q->front = new_node;
    } else {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->size++;
    return 1;
}

int dequeue(Queue *q, int *x) {
    if (is_empty_queue(q)) return 0;
    Node *temp = q->front;
    *x = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return 1;
}

int sum_queue(Queue *q) {
    if (is_empty_queue(q)) return 0;
    int sum = 0;
    Queue temp_queue;
    init_queue(&temp_queue);
    while (!is_empty_queue(q)) {
        int x;
        dequeue(q, &x);
        sum += x;
        enqueue(&temp_queue, x);
    }
    while (!is_empty_queue(&temp_queue)) {
        int x;
        dequeue(&temp_queue, &x);
        enqueue(q, x);
    }
    return sum;
}

void free_queue(Queue *q) {
    while (!is_empty_queue(q)) {
        int x;
        dequeue(q, &x);
    }
}

int main() {
    Queue q;
    init_queue(&q);
    int n;

    printf("Enter the number of elements in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d integers for the queue: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            printf("Error: Invalid integer input.\n");
            free_queue(&q);
            return 1;
        }
        if (!enqueue(&q, x)) {
            printf("Error: Memory allocation failed.\n");
            free_queue(&q);
            return 1;
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = sum_queue(&q);
    printf("Sum of queue elements: %d\n", result);

    free_queue(&q);
    return 0;
}

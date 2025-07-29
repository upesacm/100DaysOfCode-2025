#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

Queue* init_queue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->data = (int*)malloc(capacity * sizeof(int));
    if (!q->data) {
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool is_empty_queue(Queue *q) {
    return q->size == 0;
}

bool is_full_queue(Queue *q) {
    return q->size == q->capacity;
}

// Enqueue element
bool enqueue(Queue *q, int x) {
    if (is_full_queue(q)) return false;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = x;
    q->size++;
    return true;
}

bool dequeue(Queue *q, int *x) {
    if (is_empty_queue(q)) return false;
    *x = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return true;
}

void display_queue(Queue *q) {
    if (is_empty_queue(q)) {
        printf("Queue is empty\n");
        return;
    }

    int count = q->size;
    for (int i = 0; i < count; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d", q->data[index]);
        if (i < count - 1) printf(" ");
    }
    printf("\n");
}

void free_queue(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

int main() {
    int n;
    printf("Enter the number of elements in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    Queue *q = init_queue(n);
    if (!q) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers for the queue: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            printf("Error: Invalid integer input.\n");
            free_queue(q);
            return 1;
        }
        if (!enqueue(q, x)) {
            printf("Error: Queue overflow.\n");
            free_queue(q);
            return 1;
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    display_queue(q);

    free_queue(q);

    return 0;
}

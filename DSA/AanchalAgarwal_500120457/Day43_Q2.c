#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAX_LEN 20

// Queue node structure for string queue
typedef struct {
    char items[MAX][MAX_LEN];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, const char *str) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        exit(1);
    }
    strcpy(q->items[++(q->rear)], str);
}

char* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    return q->items[(q->front)++];
}

// Function to generate binary numbers from 1 to n
void generateBinaryNumbers(int n) {
    Queue q;
    initQueue(&q);

    enqueue(&q, "1");

    for (int i = 0; i < n; i++) {
        char *curr = dequeue(&q);
        printf("%s ", curr);

        char str0[MAX_LEN], str1[MAX_LEN];
        snprintf(str0, MAX_LEN, "%s0", curr);
        snprintf(str1, MAX_LEN, "%s1", curr);

        enqueue(&q, str0);
        enqueue(&q, str1);
    }
    printf("\n");
}

// 🔍 Example usage
int main() {
    int n = 5;
    printf("Binary numbers from 1 to %d:\n", n);
    generateBinaryNumbers(n);  // Output: 1 10 11 100 101
    return 0;
}

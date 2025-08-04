#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void init_stack(Stack *s, int initial_capacity) {
    s->data = (int *)malloc(initial_capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = initial_capacity;
}

void push(Stack *s, int x) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
        if (s->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    s->data[++(s->top)] = x;
}

int pop(Stack *s) {
    if (s->top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

void free_stack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

void init_queue(Queue *q, int initial_capacity) {
    q->data = (int *)malloc(initial_capacity * sizeof(int));
    if (q->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = initial_capacity;
}

bool is_empty_queue(Queue *q) {
    return q->size == 0;
}

bool is_full_queue(Queue *q) {
    return q->size == q->capacity;
}

void resize_queue(Queue *q) {
    int new_capacity = q->capacity * 2;
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < q->size; i++) {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }

    free(q->data);
    q->data = new_data;
    q->front = 0;
    q->rear = q->size - 1;
    q->capacity = new_capacity;
}

void enqueue(Queue *q, int x) {
    if (is_full_queue(q)) {
        resize_queue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(Queue *q) {
    if (is_empty_queue(q)) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

void free_queue(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = 0;
}

void reverse_k_elements(Queue *q, int k) {
    if (k <= 0 || k > q->size) return;

    Stack s;
    init_stack(&s, k);

    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    while (s.top >= 0) {
        enqueue(q, pop(&s));
    }

    for (int i = 0; i < q->size - k; i++) {
        enqueue(q, dequeue(q));
    }

    free_stack(&s);
}

void print_queue(Queue *q) {
    printf("[");
    for (int i = 0, index = q->front; i < q->size; i++, index = (index + 1) % q->capacity) {
        printf("%d", q->data[index]);
        if (i < q->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    Queue q;
    int n, k;

    printf("Enter the number of elements in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid number of elements\n");
        return EXIT_FAILURE;
    }

    init_queue(&q, n > 0 ? n : 1);

    printf("Enter %d integers for the queue: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Invalid integer input\n");
            free_queue(&q);
            return EXIT_FAILURE;
        }
        enqueue(&q, x);
    }

    printf("Enter k (number of elements to reverse): ");
    if (scanf("%d", &k) != 1 || k < 0 || k > n) {
        fprintf(stderr, "Invalid k value\n");
        free_queue(&q);
        return EXIT_FAILURE;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    reverse_k_elements(&q, k);
    printf("Queue after reversing first %d elements: ", k);
    print_queue(&q);

    free_queue(&q);
    return EXIT_SUCCESS;
}

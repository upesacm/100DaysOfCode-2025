#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char **data;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

Queue* init_queue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->data = (char**)malloc(capacity * sizeof(char*));
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
bool enqueue(Queue *q, const char *str) {
    if (is_full_queue(q)) return false;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = strdup(str);
    if (!q->data[q->rear]) return false;
    q->size++;
    return true;
}

char* dequeue(Queue *q) {
    if (is_empty_queue(q)) return NULL;
    char *str = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return str;
}

void free_queue(Queue *q) {
    if (!q) return;
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        free(q->data[index]);
    }
    free(q->data);
    free(q);
}

char** generate_binary_numbers(int n, int *result_size) {
    if (n <= 0) {
        *result_size = 0;
        return NULL;
    }

    int capacity = n * 2;
    Queue *q = init_queue(capacity);
    if (!q) {
        *result_size = 0;
        return NULL;
    }

    if (!enqueue(q, "1")) {
        free_queue(q);
        *result_size = 0;
        return NULL;
    }

    char **result = (char**)malloc(n * sizeof(char*));
    if (!result) {
        free_queue(q);
        *result_size = 0;
        return NULL;
    }

    *result_size = 0;

    while (!is_empty_queue(q) && *result_size < n) {
        char *curr = dequeue(q);
        if (!curr) break;

        result[*result_size] = curr;
        (*result_size)++;

        int curr_len = strlen(curr);
        char *next0 = (char*)malloc(curr_len + 2);
        char *next1 = (char*)malloc(curr_len + 2);
        if (!next0 || !next1) {
            free(next0);
            free(next1);
            free(curr);
            break;
        }
        sprintf(next0, "%s0", curr);
        sprintf(next1, "%s1", curr);

        if (strlen(next0) <= 32) {
            enqueue(q, next0);
        }
        if (strlen(next1) <= 32) {
            enqueue(q, next1);
        }
        free(next0);
        free(next1);
    }

    free_queue(q);
    return result;
}

void print_result(char **result, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"", result[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void free_result(char **result, int size) {
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Invalid n value. n must be a positive integer.\n");
        return 1;
    }

    int result_size;
    char **result = generate_binary_numbers(n, &result_size);

    if (result_size == 0 || !result) {
        printf("Error: Failed to generate binary numbers.\n");
        return 1;
    }

    print_result(result, result_size);
    free_result(result, result_size);

    return 0;
}

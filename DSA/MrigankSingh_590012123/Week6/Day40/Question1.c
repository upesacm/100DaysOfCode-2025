#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack *s, int initial_capacity) {
    s->data = (int *)malloc(initial_capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = initial_capacity;
}

bool is_empty(Stack *s) {
    return s->top < 0;
}

void resize_stack(Stack *s) {
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void push(Stack *s, int x) {
    if (s->top == s->capacity - 1) {
        resize_stack(s);
    }
    s->data[++(s->top)] = x;
}

int pop(Stack *s) {
    if (is_empty(s)) {
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

int find_celebrity(int **matrix, int n) {
    Stack s;
    init_stack(&s, n);

    for (int i = 0; i < n; i++) {
        push(&s, i);
    }

    while (s.top >= 1) {
        int a = pop(&s);
        int b = pop(&s);
        if (matrix[a][b]) {
            push(&s, b);
        } else {
            push(&s, a);
        }
    }

    if (is_empty(&s)) {
        free_stack(&s);
        return -1;
    }

    int candidate = pop(&s);
    free_stack(&s);

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (matrix[i][candidate] == 0 || matrix[candidate][i] == 1) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {
    int n;
    printf("Enter the number of people (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of people\n");
        return EXIT_FAILURE;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");

            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return EXIT_FAILURE;
        }
    }

    printf("Enter the %d x %d matrix (0 or 1 for each entry):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1 || (matrix[i][j] != 0 && matrix[i][j] != 1)) {
                fprintf(stderr, "Invalid matrix entry. Use 0 or 1.\n");

                for (int k = 0; k < n; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                return EXIT_FAILURE;
            }
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int celebrity = find_celebrity(matrix, n);

    printf("Celebrity: %d\n", celebrity);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack *s, int initial_capacity) {
    s->data = (char *)malloc(initial_capacity * sizeof(char));
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
    s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    if (s->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void push(Stack *s, char c) {
    if (s->top == s->capacity - 1) {
        resize_stack(s);
    }
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

void free_stack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

char *remove_k_digits(const char *num, int k) {
    int len = strlen(num);
    if (k >= len) {
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    Stack s;
    init_stack(&s, len);

    for (int i = 0; i < len; i++) {
        while (k > 0 && !is_empty(&s) && peek(&s) > num[i]) {
            pop(&s);
            k--;
        }
        push(&s, num[i]);
    }

    while (k > 0 && !is_empty(&s)) {
        pop(&s);
        k--;
    }

    int start = 0;
    while (start <= s.top && s.data[start] == '0') {
        start++;
    }

    if (start > s.top) {
        free_stack(&s);
        char *result = (char *)malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    int result_len = s.top - start + 1;
    char *result = (char *)malloc((result_len + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < result_len; i++) {
        result[i] = s.data[start + i];
    }
    result[result_len] = '\0';

    free_stack(&s);
    return result;
}

int main() {
    char *num = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;
    int k;

    printf("Enter the number (as a string): ");
    chars_read = getline(&num, &buffer_size, stdin);
    if (chars_read == -1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    if (chars_read > 0 && num[chars_read - 1] == '\n') {
        num[chars_read - 1] = '\0';
    }

    if (strlen(num) == 0) {
        fprintf(stderr, "Error: Empty number\n");
        free(num);
        return EXIT_FAILURE;
    }

    printf("Enter the number of digits to remove (k): ");
    if (scanf("%d", &k) != 1 || k < 0 || k > (int)strlen(num)) {
        fprintf(stderr, "Error: Invalid k value\n");
        free(num);
        return EXIT_FAILURE;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char *result = remove_k_digits(num, k);
    printf("\"%s\"\n", result);

    free(num);
    free(result);
    return EXIT_SUCCESS;
}

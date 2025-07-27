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

char* remove_adjacent_duplicates(const char *input) {
    int len = strlen(input);
    if (len == 0) {
        char *result = (char *)malloc(1);
        *result = '\0';
        return result;
    }

    Stack s;
    init_stack(&s, len);

    for (int i = 0; input[i] != '\0'; i++) {
        if (!is_empty(&s) && peek(&s) == input[i]) {
            pop(&s);
        } else {
            push(&s, input[i]);
        }
    }

    char *result = (char *)malloc((s.top + 2) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= s.top; i++) {
        result[i] = s.data[i];
    }
    result[s.top + 1] = '\0';

    free_stack(&s);
    return result;
}

int main() {
    char *input = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;

    printf("Enter a string: ");
    chars_read = getline(&input, &buffer_size, stdin);
    
    if (chars_read == -1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    if (chars_read > 0 && input[chars_read - 1] == '\n') {
        input[chars_read - 1] = '\0';
    }

    char *output = remove_adjacent_duplicates(input);

    printf("\"%s\"\n", output);

    free(input);
    free(output);
    return EXIT_SUCCESS;
}

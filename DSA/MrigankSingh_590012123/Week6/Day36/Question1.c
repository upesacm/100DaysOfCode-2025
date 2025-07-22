#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* reverse_string(const char *str) {
    int len = strlen(str);
    if (len == 0) {
        char *result = (char *)malloc(1);
        *result = '\0';
        return result;
    }

    Stack s;
    init_stack(&s, len);

    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        free_stack(&s);
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        result[i] = pop(&s);
    }
    result[len] = '\0';

    free_stack(&s);
    return result;
}

int main() {
    char input[1024];

    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    char *reversed = reverse_string(input);
    if (reversed == NULL) {
        printf("Error: Failed to reverse string (memory issue).\n");
        return 1;
    }

    printf("Reversed: %s\n", reversed);

    free(reversed);
    return 0;
}
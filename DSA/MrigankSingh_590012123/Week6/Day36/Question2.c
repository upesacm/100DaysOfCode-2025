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
        return '\0';
    }
    return s->data[(s->top)--];
}

void free_stack(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

int is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int is_balanced(const char *str) {
    int len = strlen(str);
    Stack s;
    init_stack(&s, len > 0 ? len : 1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            char top_char = pop(&s);
            if (top_char == '\0' || !is_matching_pair(top_char, str[i])) {
                free_stack(&s);
                return 0;
            }
        }
    }

    int result = (s.top == -1);
    free_stack(&s);
    return result;
}

int main() {
    char *input = NULL;
    size_t buffer_size = 0;

    printf("Enter a string with parentheses: ");
    ssize_t chars_read = getline(&input, &buffer_size, stdin);
    
    if (chars_read == -1) {
        printf("Error: Failed to read input.\n");
        free(input);
        return 1;
    }

    if (chars_read > 0 && input[chars_read - 1] == '\n') {
        input[chars_read - 1] = '\0';
    }

    int result = is_balanced(input);
    printf("%s\n", result ? "Balanced" : "Not Balanced");

    free(input);
    return 0;
}
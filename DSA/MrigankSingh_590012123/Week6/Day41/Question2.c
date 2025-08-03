#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *data;
    size_t capacity;
    size_t length;
} DynamicString;

void init_dynamic_string(DynamicString *ds, size_t initial_capacity) {
    ds->data = (char *)malloc(initial_capacity);
    if (ds->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    ds->capacity = initial_capacity;
    ds->length = 0;
    ds->data[0] = '\0';
}

void append_char(DynamicString *ds, char c) {
    if (ds->length + 1 >= ds->capacity) {
        ds->capacity *= 2;
        ds->data = (char *)realloc(ds->data, ds->capacity);
        if (ds->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    ds->data[ds->length++] = c;
    ds->data[ds->length] = '\0';
}

void append_string(DynamicString *ds, const char *str) {
    size_t str_len = strlen(str);
    while (ds->length + str_len >= ds->capacity) {
        ds->capacity *= 2;
        ds->data = (char *)realloc(ds->data, ds->capacity);
        if (ds->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    strcat(ds->data, str);
    ds->length += str_len;
}

void free_dynamic_string(DynamicString *ds) {
    free(ds->data);
    ds->data = NULL;
    ds->capacity = 0;
    ds->length = 0;
}

typedef struct {
    int *data;
    int top;
    int capacity;
} NumStack;

typedef struct {
    DynamicString *data;
    int top;
    int capacity;
} StrStack;

void init_num_stack(NumStack *s, int initial_capacity) {
    s->data = (int *)malloc(initial_capacity * sizeof(int));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = initial_capacity;
}

void init_str_stack(StrStack *s, int initial_capacity) {
    s->data = (DynamicString *)malloc(initial_capacity * sizeof(DynamicString));
    if (s->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < initial_capacity; i++) {
        init_dynamic_string(&s->data[i], 16);
    }
    s->top = -1;
    s->capacity = initial_capacity;
}

void push_num(NumStack *s, int x) {
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

void push_str(StrStack *s, const char *str) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->data = (DynamicString *)realloc(s->data, s->capacity * sizeof(DynamicString));
        if (s->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }

        for (int i = s->top + 1; i < s->capacity; i++) {
            init_dynamic_string(&s->data[i], 16);
        }
    }
    s->top++;
    free_dynamic_string(&s->data[s->top]);
    init_dynamic_string(&s->data[s->top], strlen(str) + 1);
    append_string(&s->data[s->top], str);
}

int pop_num(NumStack *s) {
    if (s->top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

char *pop_str(StrStack *s) {
    if (s->top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char *result = strdup(s->data[s->top].data);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    free_dynamic_string(&s->data[s->top]);
    s->top--;
    return result;
}

void free_num_stack(NumStack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}

void free_str_stack(StrStack *s) {
    for (int i = 0; i <= s->top; i++) {
        free_dynamic_string(&s->data[i]);
    }
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
}
char *decode_string(const char *input) {
    NumStack num_stack;
    StrStack str_stack;
    init_num_stack(&num_stack, 16);
    init_str_stack(&str_stack, 16);
    
    DynamicString curr_str;
    init_dynamic_string(&curr_str, 16);
    int num = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
        } else if (input[i] == '[') {
            push_num(&num_stack, num);
            push_str(&str_stack, curr_str.data);
            num = 0;
            free_dynamic_string(&curr_str);
            init_dynamic_string(&curr_str, 16);
        } else if (input[i] == ']') {
            int repeat_count = pop_num(&num_stack);
            char *prev_str = pop_str(&str_stack);
          
            DynamicString temp;
            init_dynamic_string(&temp, curr_str.length * repeat_count + 1);
            append_string(&temp, prev_str);
            free(prev_str);
            
            for (int j = 0; j < repeat_count; j++) {
                append_string(&temp, curr_str.data);
            }
            
            free_dynamic_string(&curr_str);
            curr_str = temp;
        } else {
            append_char(&curr_str, input[i]);
        }
    }

    char *result = strdup(curr_str.data);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    free_dynamic_string(&curr_str);
    free_num_stack(&num_stack);
    free_str_stack(&str_stack);
    
    return result;
}

int main() {
    char *input = NULL;
    size_t buffer_size = 0;
    ssize_t chars_read;

    printf("Enter an encoded string: ");
    chars_read = getline(&input, &buffer_size, stdin);
    
    if (chars_read == -1) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    if (chars_read > 0 && input[chars_read - 1] == '\n') {
        input[chars_read - 1] = '\0';
    }

    char *output = decode_string(input);
    printf("\"%s\"\n", output);

    free(input);
    free(output);
    return EXIT_SUCCESS;
}

//Genrating binary numbers 1 to N using QUeue.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Queue of Strings Data Structure ---
typedef struct {
    char** items;
    int front, rear, size, capacity;
} StringQueue;

StringQueue* createStringQueue(int capacity) {
    StringQueue* q = (StringQueue*)malloc(sizeof(StringQueue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->items = (char**)malloc(q->capacity * sizeof(char*));
    return q;
}

void enqueueString(StringQueue* q, char* item) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = item;
    q->size++;
}

char* dequeueString(StringQueue* q) {
    if (q->size == 0) return NULL;
    char* item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}


char** generateBinaryNumbers(int n) {
    if (n <= 0) return NULL;

    StringQueue* q = createStringQueue(n + 1);
    
    char** result = (char**)malloc(n * sizeof(char*));
    
    enqueueString(q, strdup("1"));

    for (int i = 0; i < n; i++) {
        result[i] = dequeueString(q);
        
        char* current = result[i];
        int len = strlen(current);

        char* next_zero = (char*)malloc(len + 2);
        strcpy(next_zero, current);
        strcat(next_zero, "0");
        
        char* next_one = (char*)malloc(len + 2);
        strcpy(next_one, current);
        strcat(next_one, "1");

        // Enqueue the newly generated numbers
        enqueueString(q, next_zero);
        enqueueString(q, next_one);
    }
    
    while(q->size > 0) {
        free(dequeueString(q));
    }
    free(q->items);
    free(q);

    return result;
}

int main() {
    int n = 5;
    printf("Generating binary numbers from 1 to %d:\n", n);
    char** result = generateBinaryNumbers(n);

    if (result != NULL) {
        printf("[");
        for (int i = 0; i < n; i++) {
            printf("\"%s\"", result[i]);
            if (i < n - 1) printf(", ");
            free(result[i]);
        }
        printf("]\n");
        free(result); 
    }
    return 0;
}
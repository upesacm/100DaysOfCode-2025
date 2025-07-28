#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    char data[MAX][MAX];
    int front, rear;
} StringQueue;

void enqueueStr(StringQueue *q, const char *str) {
    if (q->rear == MAX - 1) return;
    strcpy(q->data[++q->rear], str);
    if (q->front == -1) q->front = 0;
}

char* dequeueStr(StringQueue *q) {
    if (q->front == -1 || q->front > q->rear) return NULL;
    return q->data[q->front++];
}


void generateBinaryNumbers(int n) {
    StringQueue q = {.front = -1, .rear = -1};

    enqueueStr(&q, "1");

    for (int i = 0; i < n; i++) {
        char *s = dequeueStr(&q);
        printf("%s ", s);

        char s1[MAX], s2[MAX];
        sprintf(s1, "%s0", s);
        sprintf(s2, "%s1", s);

        enqueueStr(&q, s1);
        enqueueStr(&q, s2);
    }
    printf("\n");
}


int main() {
    int n = 5;
    generateBinaryNumbers(n);  
    return 0;
}


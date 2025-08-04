#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char* arr[MAX];
    int front, rear;
} QueueStr;

void enqueueStr(QueueStr* q, char* str) {
    q->arr[++q->rear] = strdup(str);
    if (q->front == -1) q->front = 0;
}

char* dequeueStr(QueueStr* q) {
    if (q->front == -1 || q->front > q->rear) return NULL;
    return q->arr[q->front++];
}

void generateBinary(int n) {
    QueueStr q = {{0}, -1, -1};
    enqueueStr(&q, "1");
    for (int i = 1; i <= n; i++) {
        char* s = dequeueStr(&q);
        printf("\"%s\"%s", s, i == n ? "\n" : ", ");
        char temp1[MAX], temp2[MAX];
        strcpy(temp1, s); strcat(temp1, "0");
        strcpy(temp2, s); strcat(temp2, "1");
        enqueueStr(&q, temp1);
        enqueueStr(&q, temp2);
        free(s);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}

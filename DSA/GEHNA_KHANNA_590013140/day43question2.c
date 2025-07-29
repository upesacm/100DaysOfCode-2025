#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char* queue[MAX];
int front = 0, rear = 0;

void enqueue(char* str) {
    queue[rear++] = str;
}

char* dequeue() {
    return queue[front++];
}

void generateBinary(int n) {
    enqueue(strdup("1"));
    for (int i = 0; i < n; i++) {
        char* current = dequeue();
        printf("%s\n", current);
        char* s1 = (char*)malloc(strlen(current) + 2);
        char* s2 = (char*)malloc(strlen(current) + 2);
        strcpy(s1, current);
        strcat(s1, "0");
        strcpy(s2, current);
        strcat(s2, "1");
        enqueue(s1);
        enqueue(s2);
        free(current);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}

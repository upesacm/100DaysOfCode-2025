#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char* queue[MAX];
int front = 0, rear = -1;
void enqueue(char *str) {
    queue[++rear] = str;
}
char* dequeue() {
    return queue[front++];
}
int main() {
    int n;
    printf("enter value of n \n");
    scanf("%d", &n);
    enqueue(strdup("1"));

    for (int i = 0; i < n; i++) {
        char *curr = dequeue();
        printf("%s ", curr);

        char *s0 = (char*)malloc(strlen(curr) + 2);
        char *s1 = (char*)malloc(strlen(curr) + 2);

        strcpy(s0, curr);
        strcpy(s1, curr);
        strcat(s0, "0");
        strcat(s1, "1");

        enqueue(s0);
        enqueue(s1);

        free(curr);
    }

    return 0;
}

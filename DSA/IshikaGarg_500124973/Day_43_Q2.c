#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void generateBinaryNumbers(int n) {
    char* queue[MAX];
    int front = 0, rear = 0;

    // Enqueue first binary number
    queue[rear++] = strdup("1");

    for (int i = 1; i <= n; i++) {
        char* current = queue[front++];
        printf("%s ", current);

        // Create binary numbers by appending 0 and 1
        char* s1 = malloc(strlen(current) + 2);
        char* s2 = malloc(strlen(current) + 2);

        strcpy(s1, current);
        strcat(s1, "0");
        queue[rear++] = s1;

        strcpy(s2, current);
        strcat(s2, "1");
        queue[rear++] = s2;

        free(current);
    }

    printf("\n");
}

int main() {
    int n = 5;
    generateBinaryNumbers(n);  // Output: 1 10 11 100 101
    return 0;
}


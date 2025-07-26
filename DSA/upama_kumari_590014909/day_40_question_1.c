#include <stdio.h>
#include <stdlib.h>

int findCelebrity(int** M, int n) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    while (top >= 1) {
        int A = stack[top--];
        int B = stack[top--];

        if (M[A][B] == 1)
            stack[++top] = B; 
        else
            stack[++top] = A; 
    }

    int candidate = stack[top--];
    free(stack);

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (M[candidate][i] == 1 || M[i][candidate] == 0)
                return -1;
        }
    }

    return candidate;
}

int main() {
    int n = 3;

    int** M = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        M[i] = (int*)malloc(n * sizeof(int));

    int input[3][3] = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = input[i][j];

    int result = findCelebrity(M, n);
    if (result == -1)
        printf("No celebrity found.\n");
    else
        printf("Celebrity is person %d\n", result);

    for (int i = 0; i < n; i++)
        free(M[i]);
    free(M);

    return 0;
}

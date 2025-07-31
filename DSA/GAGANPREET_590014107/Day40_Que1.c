#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int knows(int matrix[MAX][MAX], int a, int b) {
    return matrix[a][b];
}

int findCelebrity(int matrix[MAX][MAX], int n) {
    int stack[MAX];
    int top = -1;


    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }


    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(matrix, a, b)) {
        
            stack[++top] = b;
        } else {
        
            stack[++top] = a;
        }
    }

    int candidate = stack[top];

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(matrix, candidate, i) || !knows(matrix, i, candidate)) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {
    int matrix1[MAX][MAX] = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int n1 = 3;
    printf("Celebrity in matrix1: %d\n", findCelebrity(matrix1, n1)); 

    int matrix2[MAX][MAX] = {
        {0, 1},
        {1, 0}
    };
    int n2 = 2;
    printf("Celebrity in matrix2: %d\n", findCelebrity(matrix2, n2)); 

    return 0;
}

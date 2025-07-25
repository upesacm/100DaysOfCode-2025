#include <stdio.h>

int knows(int a, int b, int matrix[][100], int n) {
    return matrix[a][b];
}

int findCelebrity(int matrix[][100], int n) {
    int stack[100], top = -1;
    for (int i = 0; i < n; i++) stack[++top] = i;

    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];
        if (knows(a, b, matrix, n)) stack[++top] = b;
        else stack[++top] = a;
    }

    int candidate = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(candidate, i, matrix, n) || !knows(i, candidate, matrix, n)))
            return -1;
    }

    return candidate;
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("%d\n", findCelebrity(matrix, n));
    return 0;
}

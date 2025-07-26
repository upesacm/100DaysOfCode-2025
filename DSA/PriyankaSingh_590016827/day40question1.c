
#include <stdio.h>

#define MAX 100

int knows(int M[MAX][MAX], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[MAX][MAX], int n) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++)
        stack[++top] = i;

    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(M, a, b))
            stack[++top] = b;
        else
            stack[++top] = a;
    }

    int candidate = stack[top];

    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate)))
            return -1;
    }

    return candidate;
}

int main() {
    int n;
    printf("Enter number of people: ");
    scanf("%d", &n);
    int M[MAX][MAX];
    printf("Enter relationship matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);

    int celeb = findCelebrity(M, n);
    printf("Celebrity: %d\n", celeb);
    return 0;
}

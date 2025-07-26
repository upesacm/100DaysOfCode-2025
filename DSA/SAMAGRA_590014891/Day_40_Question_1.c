#include <stdio.h>

#define MAX 100

int knows(int M[MAX][MAX], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[MAX][MAX], int n) {
    int stack[MAX], top = -1;
    for (int i = 0; i < n; i++) stack[++top] = i;
    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];
        if (knows(M, a, b)) stack[++top] = b;
        else stack[++top] = a;
    }
    if (top == -1) return -1;
    int cand = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != cand && (M[cand][i] == 1 || M[i][cand] == 0)) return -1;
    }
    return cand;
}

int main() {
    int M[MAX][MAX], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    printf("%d\n", findCelebrity(M, n));
    return 0;
}

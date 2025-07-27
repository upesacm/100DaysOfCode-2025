#include <stdio.h>

#define MAX 100

int knows(int M[MAX][MAX], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[MAX][MAX], int n) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    while (top >= 1) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(M, a, b)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }

    int cand = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            if (M[cand][i] != 0 || M[i][cand] != 1)
                return -1;
        }
    }

    return cand;
}

int main() {
    int n, M[MAX][MAX];

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter %d x %d matrix (0 or 1):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);

    int result = findCelebrity(M, n);

    if (result == -1)
        printf("No celebrity found.\n");
    else
        printf("Celebrity is person %d\n", result);

    return 0;
}

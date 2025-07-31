#include <stdio.h>
#include <stdlib.h>

int** adj;
int N;

int knows(int a, int b) {
    return adj[a][b];
}

int main() {
    scanf("%d", &N);

    adj = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        adj[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int* stack = (int*)malloc(N * sizeof(int));
    int top = -1;

    for (int i = 0; i < N; i++) {
        stack[++top] = i;
    }

    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(a, b)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }

    int potentialCelebrity = -1;
    if (top != -1) {
        potentialCelebrity = stack[top];
    }

    int isCelebrity = 1;
    if (potentialCelebrity != -1) {
        for (int i = 0; i < N; i++) {
            if (i == potentialCelebrity) continue;

            if (knows(potentialCelebrity, i) || !knows(i, potentialCelebrity)) {
                isCelebrity = 0;
                break;
            }
        }
    } else {
        isCelebrity = 0;
    }


    if (isCelebrity) {
        printf("%d\n", potentialCelebrity);
    } else {
        printf("-1\n");
    }

    for (int i = 0; i < N; i++) {
        free(adj[i]);
    }
    free(adj);
    free(stack);

    return 0;
}

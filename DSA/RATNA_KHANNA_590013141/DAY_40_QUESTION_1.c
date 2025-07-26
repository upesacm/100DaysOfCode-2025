#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int knows(int **M, int a, int b) {
    return M[a][b];
}

int findCelebrity(int **M, int n) {
    for (int i = 0; i < n; i++) {
        push(i);
    }

    while (top >= 1) {
        int A = pop();
        int B = pop();
        if (knows(M, A, B)) {
            push(B);
        } else {
            push(A);
        }
    }
    if (top == -1) return -1; 
    int candidate = pop();
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
            return -1;
        }
    }

    return candidate;
}

int main() {
    int n;
    printf("Enter number of people at the party: ");
    scanf("%d", &n);
    int **M = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the %dx%d matrix (0 or 1):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    int result = findCelebrity(M, n);
    if (result == -1)
    {
        printf("No celebrity found.\n");
        printf("-1\n");
    }
    else
        printf("Celebrity is person %d\n", result);

    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

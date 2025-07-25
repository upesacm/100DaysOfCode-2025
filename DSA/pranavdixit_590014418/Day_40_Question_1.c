#include <stdio.h>

#define N 3

int M[N][N] = {
    {0, 1, 1},
    {0, 0, 1},
    {0, 0, 0}
};

int knows(int a, int b) {
    return M[a][b];
}

int findCelebrity(int n) {
    int stack[n], top = -1;

    for (int i = 0; i < n; i++)
        stack[++top] = i;

    while (top >= 1) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(a, b))
            stack[++top] = b;
        else
            stack[++top] = a;
    }

    int candidate = stack[top];
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(candidate, i) || !knows(i, candidate)))
            return -1;
    }
    return candidate;
}

int main() {
    int result = findCelebrity(N);
    printf("%d\n", result);
    return 0;
}

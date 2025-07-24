#include <stdio.h>
#define MAX 100

int knows(int M[MAX][MAX], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[MAX][MAX], int n) {
    int stack[MAX];
    int top = -1;

    // Push everyone to stack
    for (int i = 0; i < n; i++)
        stack[++top] = i;

    // Eliminate non-celebrities
    while (top > 1) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(M, a, b))
            stack[++top] = b;  // a can't be celeb
        else
            stack[++top] = a;  // b can't be celeb
    }

    int candidate = stack[top];

    // Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate)))
            return -1;
    }

    return candidate;
}

int main() {
    int M[MAX][MAX] = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int n = 3;

    int result = findCelebrity(M, n);
    printf("Celebrity: %d\n", result); // Output: 2

    return 0;
}


#include <stdio.h>
#define MAX 100


int MATRIX[MAX][MAX];


int knows(int a, int b) {
    return MATRIX[a][b];
}


int findCelebrity(int n) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++)
        stack[++top] = i;

    while (top > 0) {
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
    int n = 3;
    int input1[3][3] = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            MATRIX[i][j] = input1[i][j];

    printf("Celebrity: %d\n", findCelebrity(n)); 

    int input2[2][2] = {
        {0, 1},
        {1, 0}
    };
    n = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            MATRIX[i][j] = input2[i][j];

    printf("Celebrity: %d\n", findCelebrity(n)); 

    return 0;
}

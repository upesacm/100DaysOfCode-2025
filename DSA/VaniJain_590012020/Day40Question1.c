#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int knows(int **M, int a, int b) 
{
    return M[a][b];
}
int findCelebrity(int **M, int n) 
{
    int stack[MAX], top = -1;
    for (int i = 0; i < n; i++) 
    {
        stack[++top] = i;
    }
    while (top >= 1) 
    {
        int A = stack[top--];
        int B = stack[top--];
        if (knows(M, A, B)) 
        {
            stack[++top] = B;
        } 
        else 
        {
            stack[++top] = A;
        }
    }
    int candidate = stack[top];
    for (int i = 0; i < n; i++) 
    {
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate))) 
        {
            return -1; 
        }
    }
    return candidate; 
}
int main() 
{
    int n;
    printf("Enter number of people at the party: ");
    scanf("%d", &n);
    int **M = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) 
    {
        M[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the matrix (0 or 1) where M[i][j] = 1 if person i knows person j:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &M[i][j]);
        }
    }
    int celeb = findCelebrity(M, n);
    if (celeb == -1) 
    {
        printf("There is no celebrity in the party.\n");
    } 
    else 
    {
        printf("Person %d is the celebrity.\n", celeb);
    }
    for (int i = 0; i < n; i++) 
    {
        free(M[i]);
    }
    free(M);
    return 0;
}

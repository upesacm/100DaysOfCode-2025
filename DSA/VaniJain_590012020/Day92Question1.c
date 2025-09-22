#include <stdio.h>
int main() 
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    if (N < 0) 
    {
        printf("Invalid input! N must be non-negative.\n");
        return 0;
    }
    if (N == 0) 
    {
        printf("Fibonacci(%d) = 0\n", N);
        return 0;
    }
    if (N == 1) 
    {
        printf("Fibonacci(%d) = 1\n", N);
        return 0;
    }
    long long fib[N+1];  
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= N; i++) 
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("Fibonacci(%d) = %lld\n", N, fib[N]);
    return 0;
}

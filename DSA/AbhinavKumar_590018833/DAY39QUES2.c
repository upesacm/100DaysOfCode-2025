// 2. Stock Span Problem
// A problem that introduces financial algorithm applications and teaches monotonic stack
// techniques for analyzing time-series data and computing backward-looking statistics
// efficiently.
// Given a list of daily stock prices, return the span of stocks for each day using a stack-based
// approach. The span represents the number of consecutive days before the current day
// with smaller or equal price. This operation is fundamental in financial
// analysis and technical indicators where you need to compute price momentum and trend
// analysis metrics. The technique uses a monotonic decreasing stack to efficiently track
// previous higher prices, enabling O(n) time complexity for span calculation. This concept is
// essential in algorithmic trading, market analysis, and time-series processing where
// efficient backward-looking computations are crucial for real-time decision making.
// This introduces financial algorithm techniques and time-series analysis methods that are
// crucial for trading systems and efficient market data processing operations.
// Your task: Use a monotonic stack to efficiently compute stock price spans by tracking
// previous higher prices for optimal time-series analysis.
// Examples
// Input:
// [100, 80, 60, 70, 60, 75, 85]
// Output:
// [1, 1, 1, 2, 1, 4, 6]
// Input:
// [10, 20, 30]
// Output:
// [1, 2, 3]
#include<stdio.h>
#include<stdlib.h>
void stockSpan(int *prices,int n){
    int *span=(int *)malloc(n*sizeof(int));
    int *stack=(int *)malloc(n*sizeof(int));
    int top=-1;
    for (int i=0;i<n;i++){
        while(top!=-1 && prices[stack[top]]<=prices[i]){
            top--;
        }
        if(top==-1){
            span[i]=i+1;
        } else {
            span[i]=i-stack[top];

        }
        stack[++top]=i;

        printf("%d ", span[i]);


    }
    printf("\n");
    free(span);
    free(stack);
}
int main(){
    int prices1[] = {100, 80, 60, 70, 60, 75, 85};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Stock spans for prices1: ");
    stockSpan(prices1, n1);

    int prices2[] = {10, 20, 30};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Stock spans for prices2: ");
    stockSpan(prices2, n2);

    return 0;
}
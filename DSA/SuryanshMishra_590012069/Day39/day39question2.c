// 2. Stock Span Problem
// A problem that introduces financial algorithm applications and teaches monotonic stack techniques for analyzing time-series data and computing backward-looking statistics efficiently.

// Given a list of daily stock prices, return the span of stocks for each day using a stack-based approach. The span represents the number of consecutive days before the current day with smaller or equal price. This operation is fundamental in financial analysis and technical indicators where you need to compute price momentum and trend analysis metrics. The technique uses a monotonic decreasing stack to efficiently track previous higher prices, enabling O(n) time complexity for span calculation. This concept is essential in algorithmic trading, market analysis, and time-series processing where efficient backward-looking computations are crucial for real-time decision making.

// This introduces financial algorithm techniques and time-series analysis methods that are crucial for trading systems and efficient market data processing operations.

// Your task: Use a monotonic stack to efficiently compute stock price spans by tracking previous higher prices for optimal time-series analysis.

// Examples
// Input:

// [100, 80, 60, 70, 60, 75, 85]
// Output:

// [1, 1, 1, 2, 1, 4, 6]
// Input:

// [10, 20, 30]
// Output:

// [1, 2, 3]
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stack[MAX];
int top = -1;
void push(int index) {
stack[++top] = index;
}
int pop() {
if (top == -1) return -1;
return stack[top--];
}
int peek() {
if (top == -1) return -1;
return stack[top];
}
void calculateSpan(int price[], int n, int span[]) {
top = -1;
span[0] = 1;
push(0);
for (int i = 1; i < n; i++) {
while (top != -1 && price[peek()] <= price[i]) {
pop();
}
if (top == -1) {
span[i] = i + 1;
} else {
span[i] = i - peek();
}
push(i);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
int main() {
int price1[] = {100, 80, 60, 70, 60, 75, 85};
int n1 = sizeof(price1) / sizeof(price1[0]);
int span1[n1];
calculateSpan(price1, n1, span1);
printf("Output 1:\n");
printArray(span1, n1);
int price2[] = {10, 20, 30};
int n2 = sizeof(price2) / sizeof(price2[0]);
int span2[n2];
calculateSpan(price2, n2, span2);
printf("Output 2:\n");
printArray(span2, n2);
return 0;
}
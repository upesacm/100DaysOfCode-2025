// 3. Remove K Digits to Make the Smallest Number
// A problem that teaches greedy optimization techniques and demonstrates monotonic stack algorithms for numerical minimization while preserving digit order constraints in mathematical optimization.

// You are given a string num representing a non-negative integer and an integer k. Remove exactly k digits from the number so that the new number is the smallest possible using a stack-based greedy approach. The technique maintains relative digit order while selecting optimal removals through monotonic stack operations. This operation is fundamental in numerical optimization and greedy algorithms where you need to minimize values under removal constraints. Understanding this concept is crucial for competitive programming, algorithmic optimization, and mathematical problem solving where greedy digit selection produces optimal results efficiently.

// This teaches greedy digit selection algorithms and monotonic optimization techniques that are essential for numerical minimization and efficient mathematical optimization operations.

// Your task: Use a monotonic stack with greedy selection to remove k digits while building the lexicographically smallest possible number.

// Examples
// Input:

// num = "1432219", k = 3
// Output:

// "1219"
// Input:

// num = "10200", k = 1
// Output:

// "200"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k >= len) return strdup("0");
    char* stack = (char*)malloc(len + 1);
    int top = -1;
    for (int i = 0; i < len; i++) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }
    top = top - k;
    stack[top + 1] = '\0';
    int start = 0;
    while (stack[start] == '0' && start <= top) start++;
    if (start > top) return strdup("0");
    return strdup(stack + start);
}
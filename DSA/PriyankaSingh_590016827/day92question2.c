#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1, prev1 = 2, curr = 0;
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    printf("%d\n", climbStairs(3)); // Output: 3
    printf("%d\n", climbStairs(4)); // Output: 5
    return 0;
}

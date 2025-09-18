#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 1) return cost[0];

    int prev2 = cost[0], prev1 = cost[1], curr = 0;
    for (int i = 2; i < costSize; i++) {
        curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int main() {
    int cost1[] = {10, 15, 20};
    printf("%d\n", minCostClimbingStairs(cost1, 3)); // Output: 15

    int cost2[] = {1,100,1,1,1,100,1,1,100,1};
    printf("%d\n", minCostClimbingStairs(cost2, 10)); // Output: 6

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int cmp(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int findMaxDeadline(Job jobs[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > max) max = jobs[i].deadline;
    return max;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) slot[i] = -1;

    int count = 0, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("%d jobs, Profit: %d\n", count, totalProfit);
}

int main() {
    Job jobs1[] = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    jobScheduling(jobs1, 4); // 2 jobs, Profit: 60

    Job jobs2[] = {{1,2,100}, {2,1,19}, {3,2,27}};
    jobScheduling(jobs2, 3); // 2 jobs, Profit: 127
    return 0;
}

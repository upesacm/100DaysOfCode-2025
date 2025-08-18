#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id, deadline, profit;
};

int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    printf("Enter job id, deadline, and profit:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    qsort(jobs, n, sizeof(struct Job), compare);

    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    int slots[max_deadline + 1];
    for (int i = 0; i <= max_deadline; i++)
        slots[i] = -1;

    int count = 0, total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("Number of jobs done: %d\n", count);
    printf("Total profit: %d\n", total_profit);
    return 0;
}

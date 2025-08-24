#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int findMaxDeadline(Job arr[], int n) {
    int maxD = arr[0].deadline;
    for (int i = 1; i < n; i++)
        if (arr[i].deadline > maxD) maxD = arr[i].deadline;
    return maxD;
}

void jobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);

    int maxD = findMaxDeadline(arr, n);
    int slot[maxD + 1];
    for (int i = 0; i <= maxD; i++) slot[i] = -1;

    int count = 0, totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                count++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    printf("%d jobs done, Profit: %d\n", count, totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job arr[n];
    printf("Enter job details (id deadline profit):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);

    jobScheduling(arr, n);
    return 0;
}

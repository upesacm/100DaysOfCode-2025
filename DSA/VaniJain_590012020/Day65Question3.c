#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int start, end;
} Task;
int compare(const void *a, const void *b) 
{
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    return (t1->end - t2->end);
}
int minRemovals(Task tasks[], int n) 
{
    qsort(tasks, n, sizeof(Task), compare);
    int count = 1;
    int lastEnd = tasks[0].end;
    for (int i = 1; i < n; i++) 
    {
        if (tasks[i].start >= lastEnd) 
        {
            count++;
            lastEnd = tasks[i].end;
        }
    }
    return n - count;
}
int main() 
{
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    Task tasks[n];
    printf("Enter start and end times of tasks:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &tasks[i].start, &tasks[i].end);
    }
    int result = minRemovals(tasks, n);
    printf("\nMinimum number of tasks to remove: %d\n", result);
    return 0;
}

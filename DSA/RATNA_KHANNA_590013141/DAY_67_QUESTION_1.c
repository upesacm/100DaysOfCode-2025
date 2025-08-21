#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the numbers:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    qsort(arr, n, sizeof(int), compare);

    if(arr[0]==0) {
        printf("Largest number: 0\n");
        return 0;
    }

    printf("Largest number: ");
    for(int i=0;i<n;i++) printf("%d",arr[i]);
    printf("\n");

    return 0;
}

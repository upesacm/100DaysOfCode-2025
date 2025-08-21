#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab); 
}

void printLargestNumber(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    
    if (arr[0] == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 30, 34, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Largest Number = ");
    printLargestNumber(arr, n);
    return 0;
}


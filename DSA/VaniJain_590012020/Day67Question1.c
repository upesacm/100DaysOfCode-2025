#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b) 
{
    char ab[50], ba[50];
    char *x = *(char **)a;
    char *y = *(char **)b;
    strcpy(ab, x);
    strcat(ab, y);
    strcpy(ba, y);
    strcat(ba, x);
    return strcmp(ba, ab);
}
void printLargestNumber(char *arr[], int n) 
{
    qsort(arr, n, sizeof(char *), compare);
    if (strcmp(arr[0], "0") == 0) 
    {
        printf("0\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%s", arr[i]);
    printf("\n");
}
int main() 
{
    char *arr[] = {"54", "546", "548", "60"};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Largest formed number: ");
    printLargestNumber(arr, n);
    return 0;
}

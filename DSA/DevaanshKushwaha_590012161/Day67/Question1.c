#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestNumber(int nums[], int n) {
    char** strs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strs[i] = (char*)malloc(12 * sizeof(char));
        sprintf(strs[i], "%d", nums[i]);
    }

    int cmp(const void* a, const void* b) {
        char* s1 = *(char**)a;
        char* s2 = *(char**)b;
        char ab[25], ba[25];
        strcpy(ab, s1);
        strcat(ab, s2);
        strcpy(ba, s2);
        strcat(ba, s1);
        return strcmp(ba, ab);
    }

    qsort(strs, n, sizeof(char*), cmp);

    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < n; i++) strcat(result, strs[i]);

    if (result[0] == '0') result[1] = '\0';

    for (int i = 0; i < n; i++) free(strs[i]);
    free(strs);

    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    char* ans = largestNumber(nums, n);
    printf("Largest number: %s\n", ans);
    free(ans);

    return 0;
}

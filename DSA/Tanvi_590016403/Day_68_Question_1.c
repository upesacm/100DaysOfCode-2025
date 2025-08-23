#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// ---------- 1. Min Jumps to Reach End ----------
int minJumps(int arr[], int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int jumps = 0, farthest = 0, end = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = (farthest > i + arr[i]) ? farthest : i + arr[i];
        if (i == end) {
            jumps++;
            end = farthest;
            if (end >= n - 1) break;
        }
    }
    return end < n - 1 ? -1 : jumps;
}

// ---------- 2. Rearrange Characters ----------
typedef struct {
    char c;
    int freq;
} Node;

int cmp(const void *a, const void *b) {
    return ((Node*)b)->freq - ((Node*)a)->freq;
}

char* rearrangeString(char *s) {
    int count[256] = {0}, n = strlen(s);
    for (int i = 0; s[i]; i++) count[(int)s[i]]++;

    Node arr[256]; int size = 0;
    for (int i = 0; i < 256; i++) if (count[i]) {
        arr[size].c = i; arr[size].freq = count[i]; size++;
    }

    qsort(arr, size, sizeof(Node), cmp);

    char *res = (char*)malloc(n + 1);
    int idx = 0;
    while (size > 1) {
        res[idx++] = arr[0].c;
        res[idx++] = arr[1].c;
        if (--arr[0].freq == 0) { arr[0] = arr[size-1]; size--; }
        if (--arr[1].freq == 0) { arr[1] = arr[size-1]; size--; }
        qsort(arr, size, sizeof(Node), cmp);
    }
    if (size == 1) {
        if (arr[0].freq > 1) { free(res); return ""; }
        res[idx++] = arr[0].c;
    }
    res[idx] = '\0';
    return res;
}

// ---------- 3. Max Sum After K Negations ----------
int cmpInt(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int largestSumAfterKNegations(int *nums, int n, int k) {
    qsort(nums, n, sizeof(int), cmpInt);
    for (int i = 0; i < n && k > 0; i++) {
        if (nums[i] < 0) { nums[i] = -nums[i]; k--; }
    }
    qsort(nums, n, sizeof(int), cmpInt);
    if (k % 2) nums[0] = -nums[0];

    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    return sum;
}

// ---------- Main ----------
int main() {
    int choice;
    printf("Choose problem:\n1. Min Jumps\n2. Rearrange Characters\n3. Max Sum After K Negations\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int arr[] = {2,3,1,1,4}, n = 5;
        printf("Min Jumps: %d\n", minJumps(arr, n));
    } 
    else if (choice == 2) {
        char s[] = "aab";
        char *res = rearrangeString(s);
        if (strlen(res) == 0) printf("Not possible\n");
        else printf("Rearranged: %s\n", res);
    } 
    else if (choice == 3) {
        int nums[] = {3, -1, 0, 2}, k = 3, n = 4;
        printf("Max Sum: %d\n", largestSumAfterKNegations(nums, n, k));
    }
    return 0;
}

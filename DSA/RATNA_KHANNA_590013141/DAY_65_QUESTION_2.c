#include <stdio.h>

struct Pair {
    int first, second;
};

// Comparator for sorting by second element
void sortPairs(struct Pair arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i].second > arr[j].second) {
                struct Pair temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Pair pairs[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &pairs[i].first, &pairs[i].second);
    }

    printf("Input:\npairs = [");
    for(int i = 0; i < n; i++) {
        printf("(%d, %d)", pairs[i].first, pairs[i].second);
        if(i != n-1) printf(", ");
    }
    printf("]\n");

    sortPairs(pairs, n);

    int count = 1;
    int last_end = pairs[0].second;

    for(int i = 1; i < n; i++) {
        if(pairs[i].first > last_end) {
            count++;
            last_end = pairs[i].second;
        }
    }

    printf("Output:\n%d\n", count);

    return 0;
}

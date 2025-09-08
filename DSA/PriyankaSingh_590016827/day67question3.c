#include <stdio.h>
#include <stdlib.h>

// Helper function for swapping
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to sort meetings by end time
void sortMeetings(int start[], int end[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (end[j] > end[j + 1]) {
                swap(&start[j], &start[j + 1]);
                swap(&end[j], &end[j + 1]);
            }
        }
    }
}

// Function to find the maximum number of non-overlapping meetings
int maxMeetings(int start[], int end[], int n) {
    sortMeetings(start, end, n);
    int count = 1;
    int last_end = end[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= last_end) {
            count++;
            last_end = end[i];
        }
    }
    return count;
}

int main() {
    // Example 1
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[] = {2, 4, 6, 7, 9, 9};
    int n1 = sizeof(start1) / sizeof(start1[0]);
    printf("Maximum number of non-overlapping meetings: %d\n", maxMeetings(start1, end1, n1));

    return 0;
}

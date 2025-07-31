#include <stdio.h>

void countEvenOdd(int arr[], int n) {
    int evenCount = 0, oddCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    printf("Even: %d, Odd: %d\n", evenCount, oddCount);
}

int main() {
    int q1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(q1)/sizeof(q1[0]);

    countEvenOdd(q1, n1);

    int q2[] = {6, 8, 10};
    int n2 = sizeof(q2)/sizeof(q2[0]);

    countEvenOdd(q2, n2);

    return 0;
}


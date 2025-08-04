#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements in each queue: ");
    scanf("%d", &n);

    int q1[n], q2[n];
    printf("Enter elements of Queue 1: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &q1[i]);

    printf("Enter elements of Queue 2: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &q2[i]);

    int identical = 1;
    for (int i = 0; i < n; i++) {
        if (q1[i] != q2[i]) {
            identical = 0;
            break;
        }
    }

    if (identical)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

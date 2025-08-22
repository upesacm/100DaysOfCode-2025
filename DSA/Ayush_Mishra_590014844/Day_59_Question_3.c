#include <stdio.h>

int areIdentical(int arr1[], int arr2[], int n1, int n2) {
    if (n1 != n2)
        return 0;
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    if (areIdentical(arr1, arr2, n1, n2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

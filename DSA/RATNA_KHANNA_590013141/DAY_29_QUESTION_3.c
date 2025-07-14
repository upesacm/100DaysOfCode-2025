#include <stdio.h>
int main() {
    int n, i;
    printf("enter value of n\n");
    scanf("%d", &n);
    printf("enter value of i\n");
    scanf("%d", &i);
    int result = n | (1 << i);
    printf("%d\n", result);
    return 0;
}

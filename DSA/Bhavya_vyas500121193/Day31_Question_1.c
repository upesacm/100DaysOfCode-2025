#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n > 0 && (n & (n - 1)) == 0)
        printf("Output: Yes\n");
    else
        printf("Output: No\n");

    return 0;
}

#include <stdio.h>

int multiplyByTwo(int n) {
    return n << 1;  
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = multiplyByTwo(num);
    printf("Result: %d\n", result);

    return 0;
}

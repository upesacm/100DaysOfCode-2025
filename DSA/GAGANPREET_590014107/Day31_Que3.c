#include <stdio.h>

int divideByTwo(int n) {
    return n >> 1;  
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = divideByTwo(num);
    printf("Result: %d\n", result);

    return 0;
}

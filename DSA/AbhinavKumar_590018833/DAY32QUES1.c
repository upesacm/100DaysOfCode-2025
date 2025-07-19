//swap two numbers using only bitwise operators
#include <stdio.h>
void swap(int *a, int *b) {
    if (a != b) { 
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}
int main(){
    printf("Enter two numbers to swap:\n");
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y); 
    printf("After swapping:");
    printf(" x = %d, y = %d\n", x, y);
    return 0;
    
}

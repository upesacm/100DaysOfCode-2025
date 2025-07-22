#include<stdio.h>
int subtractOne(int n){
    return n ^ 1;
}
int main(){
    int n = 5;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    n = 8;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    n = 4;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    n = 1;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    n = 0;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    n = -5;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));
    return 0;
}
#include<stdio.h>
int addOne(int n){
    int m = 1;
    while (m != 0) {
        int carry = n & m;
        n = n ^ m;
        m = carry << 1;
    }
    return n;
}
int main(){
    int n = 4;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", addOne(n));
    n = 0;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", addOne(n));
    n = -1;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", addOne(n));
    n = 7;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", addOne(n));
    return 0;
}
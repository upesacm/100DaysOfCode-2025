#include<stdio.h>
int toggleBit(int n, int i){
    return n ^ (1 << i);
}
int main(){
    int n1 = 10; 
    int i1 = 1;
    int result1 = toggleBit(n1, i1);
    printf("Input: n = %d, i = %d\nOutput: %d\n", n1, i1, result1);
    int n2 = 5;
    int i2 = 2;
    int result2 = toggleBit(n2, i2);
    printf("Input: n = %d, i = %d\nOutput: %d\n", n2, i2, result2);
    return 0;
}
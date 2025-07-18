#include<stdio.h>
int turnOffRightmostSetBit(int n){
    return n & (n - 1);
}
int main(){
    int n1 = 12;
    int n2 = 10;
    printf("Input 1: n = %d, Output 1: %d\n", n1, turnOffRightmostSetBit(n1));
    printf("Input 2: n = %d, Output 2: %d\n", n2, turnOffRightmostSetBit(n2));
    return 0;
}
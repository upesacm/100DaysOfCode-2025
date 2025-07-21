
#include<stdio.h>
int isolateRightmostSetBit(int n){
    return n & -n;
}
int main(){
    int n1 = 10;
    int n2 = 12;
    printf("Input 1: n = %d, Output 1: %d\n", n1, isolateRightmostSetBit(n1));
    printf("Input 2: n = %d, Output 2: %d\n", n2, isolateRightmostSetBit(n2));
    return 0;
}

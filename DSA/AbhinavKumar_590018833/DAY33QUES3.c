//isolate the rightmost set bit of a no.
#include<stdio.h>
int isolateRightmostSetBit(int n){
    return n&-n;
}
int main(){
    printf("Enter an integer..\n");
    int x;
    scanf("%d", &x);
    int result = isolateRightmostSetBit(x);
    printf("The rightmost set bit of %d is: %d\n", x, result);
    return 0;
}
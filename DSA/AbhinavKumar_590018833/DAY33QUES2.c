//turn of the rightmost set bit 
#include<stdio.h>
int turnOffRightmostSetBit(int n){
    return n&(n-1);

}
int main(){
    printf("Enter an integer..\n");
    int x;
    scanf("%d",&x);
    int result=turnOffRightmostSetBit(x);
    printf("The result after turening off the rightmost bit is: %d\n", result);
    return 0;
}

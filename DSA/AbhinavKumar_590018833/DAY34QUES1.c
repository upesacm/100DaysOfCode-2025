//  Implement addition of 1 using only bitwise operations by simulating binary arithmetic carry propagation.
#include<stdio.h>
int addOne(int n){
    int carry =1;
    while(carry!=0){
        int sum=n^carry;
        carry=(n&carry)<<1;
        n=sum;
        if (carry==0) break;

    }
    return n;

}
int main(){
    printf("Enter an integer..\n");
    int x;
    scanf("%d",&x);
    int result=addOne(x);
    printf("the result of adding one to %d is %d\n", x, result);
    return 0;
}
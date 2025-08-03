//now subtracting 1 inbuitwise:
#include<stdio.h>
int subtractOne(int n){
    int borrow=1;
    while(borrow!=0){
        int diff=n^borrow;
        borrow=(~n&borrow)<<1;
        n=diff;
        if(borrow==0) break;
    }
    return n;
}
int main(){
    printf("Enter an integer..\n");
    int x;
    scanf("%d",&x);
    int result=subtractOne(x);
    printf("the result of subtracting one to %d is %d\n", x, result);
    return 0;
}
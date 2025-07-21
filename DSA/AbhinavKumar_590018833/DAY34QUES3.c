//checking if binary represaentation of a no is a pallindrome..
#include<stdio.h>
int isBinaryPallindrome(int n){
    int reversed=0,original=n;
    while(n>0){

        reversed=(reversed<<1)|(n&1);
        n>>=1;
    }
    return reversed==original;

}
int main(){
    printf("Enter an integer..\n");
    int x;
    scanf("%d",&x);
    int result=isBinaryPallindrome(x);
    if(result) printf("the binary representation of %d is a pallindrome\n",x);
    else printf("The binary representation of %d is not a poallinmdrome\n",x);
    return 0;
}
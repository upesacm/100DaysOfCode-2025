#include<stdio.h>
//to get ith bit:
void getIthBit(int n,int i){
    int bit= (n>>i)&1;
    if(bit) printf("1\n");
    else printf("0\n");

}
int main(){
    int n,i;
    printf("Enter A no.");
    scanf("%d",&n);
    printf("Enter the bit position to check:");
    scanf("%d",&i);
    getIthBit(n,i);
    return 0;}
    
#include<stdio.h>
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; 
        n >>= 1; 
    }
    printf("Number of set bits: %d\n", count);    
}
int main(){
    int n;
    printf("Enter a no.");
    scanf("%d",&n);
    countSetBits(n);
    return 0;
}
#include <stdio.h>
void clearIthBit( int n, int i){
    n=n &~(1<<i);
    printf("Number after clearing %dth bit: %d\n", i,n);
}
int main(){
    int n, i;
    printf("Enter a no.");
    scanf("%d",&n);
    printf("Enter the bit position to clear:");
    scanf("%d",&i);
    clearIthBit(n, i);
    return 0;
}
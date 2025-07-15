#include<stdio.h>
void toggleIthBit(int n, int i) {
    n= n^(1<<i);
    printf("Number often toggles %dth bit : %d\n", i,n);

}
int main(){
    int n, i;
    printf("Enter a no.");
    scanf("%d",&n);
    printf("Enter the bit position that you wanna toggle?");
    scanf("%d", &i);
    toggleIthBit(n,i);
    return 0;
}
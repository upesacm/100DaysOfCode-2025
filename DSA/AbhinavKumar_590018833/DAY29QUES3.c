#include<stdio.h>
void setIthBit(int n, int i) {
    n = n | (1 << i);
    printf("Number after setting %dth bit: %d\n", i, n);
}
int main(){
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the bit position to set: ");
    scanf("%d", &i);
    setIthBit(n, i);
    return 0;
}
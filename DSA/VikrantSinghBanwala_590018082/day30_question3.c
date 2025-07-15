#include<stdio.h>
int countSetBits(int n){
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int main(){
    int n1 = 7; 
    int result1 = countSetBits(n1);
    printf("Input: n = %d\nOutput: %d\n", n1, result1);
    return 0;
}
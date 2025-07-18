
#include<stdio.h>
int main(){
    int arr1[] = {2, 3, 2};
    int unique1 = 0;
    for (int i = 0; i < 3; i++) {
        unique1 ^= arr1[i];
    }
    printf("%d\n", unique1);
    int arr2[] = {5, 1, 1, 5, 7};
    int unique2 = 0;
    for (int i = 0; i < 5; i++) {
        unique2 ^= arr2[i];
    }
    printf("%d\n", unique2);
    return 0;
}

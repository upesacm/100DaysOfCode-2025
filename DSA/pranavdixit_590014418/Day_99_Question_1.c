#include <stdio.h>
#include <ctype.h>

int sumPositive(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) sum += arr[i];
    }
    return sum;
}

int countVowels(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            count++;
    }
    return count;
}

int main() {
    int arr[] = {1,-2,3,-4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    char str[] = "Hello World";

    int sum = sumPositive(arr, n);
    int vowels = countVowels(str);

    printf("Sum: %d, Vowels: %d\n", sum, vowels);
    return 0;
}

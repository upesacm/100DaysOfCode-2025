#include <stdio.h>
#include <ctype.h>

int main() {
    int arr[] = {1, -2, 3, -4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    char str[] = "Hello World";

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) sum += arr[i];
    }

    int vowels = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vowels++;
    }

    printf("Sum: %d, Vowels: %d\n", sum, vowels);
    return 0;
}

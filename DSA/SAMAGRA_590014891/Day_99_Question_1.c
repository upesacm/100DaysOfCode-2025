#include <stdio.h>
#include <ctype.h>

int main() {
    int arr[] = {1, -2, 3, -4, 5};
    char str[] = "Hello World";
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, vowels = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            sum += arr[i];
    }

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            vowels++;
    }

    printf("Sum: %d, Vowels: %d\n", sum, vowels);
    return 0;
}

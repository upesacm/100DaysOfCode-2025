#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int arr[] = {1, -2, 3, -4, 5};
    char str[] = "Hello World";
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, vowels = 0;

    // Sum of positive numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            sum += arr[i];
    }

    // Count vowels
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
    }

    printf("Sum: %d, Vowels: %d\n", sum, vowels);
    return 0;
}

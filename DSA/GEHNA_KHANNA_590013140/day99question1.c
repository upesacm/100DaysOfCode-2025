#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) sum += arr[i];
    }
    char str[1000];
    getchar();
    fgets(str, sizeof(str), stdin);
    int vowels = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowels++;
    }
    printf("Sum: %d, Vowels: %d\n", sum, vowels);
    return 0;
}

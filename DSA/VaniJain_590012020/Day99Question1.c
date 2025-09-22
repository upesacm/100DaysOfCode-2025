#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() 
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    int sum = 0;
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        if (arr[i] > 0) 
        {
            sum += arr[i]; 
        }
    }
    char str[100];
    int vowelCount = 0;
    printf("Enter a string: ");
    scanf(" %[^\n]", str); 
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
        {
            vowelCount++;
        }
    }
    printf("Sum of positive numbers = %d\n", sum);
    printf("Number of vowels in the string = %d\n", vowelCount);
    return 0;
}

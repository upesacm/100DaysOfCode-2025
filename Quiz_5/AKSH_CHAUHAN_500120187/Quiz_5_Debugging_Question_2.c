#include <stdio.h>
#include <stdbool.h>

bool is_power_of_two(int n) {
    // Fix: Must be positive
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

void check_numbers(int arr[], int size) {
    printf("Checking which numbers are powers of two:\n");
    for (int i = 0; i < size; i++) {
        if (is_power_of_two(arr[i]))
            printf("%d: YES\n", arr[i]);
        else
            printf("%d: NO\n", arr[i]);
    }
}

int main() {
    int numbers[] = {0, 1, 2, 3, 4, 8, 16, -2, -8, 1024, 218, -1};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    check_numbers(numbers, size);
    return 0;
}

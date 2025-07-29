#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char queue[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (queue[i] != queue[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char queue[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    int n = sizeof(queue) / sizeof(queue[0]);

    if (isPalindrome(queue, n))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

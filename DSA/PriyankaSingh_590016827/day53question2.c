#include <stdio.h>

int maxFruit(int fruits[], int n) {
    int max_len = 0;
    int left = 0;
    int last_fruit = -1, second_last_fruit = -1;
    int last_fruit_count = 0;
    int curr_len = 0;

    for (int right = 0; right < n; right++) {
        if (fruits[right] == last_fruit || fruits[right] == second_last_fruit) {
            curr_len++;
        } else {
            curr_len = last_fruit_count + 1;
        }

        if (fruits[right] == last_fruit) {
            last_fruit_count++;
        } else {
            second_last_fruit = last_fruit;
            last_fruit = fruits[right];
            last_fruit_count = 1;
        }

        if (curr_len > max_len)
            max_len = curr_len;
    }

    return max_len;
}

int main() {
    int n;
    printf("Enter number of fruits: ");
    scanf("%d", &n);

    int fruits[n];
    printf("Enter fruit types as integers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &fruits[i]);

    int result = maxFruit(fruits, n);
    printf("Maximum number of fruits: %d\n", result);

    return 0;
}

#include <stdio.h>

int main() {
    int queue[100], freq[100], unique[100];
    int size, u = 0;

    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }

    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < u; j++) {
            if (unique[j] == queue[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[u] = queue[i];
            freq[u] = 1;
            u++;
        }
    }

    printf("{");
    for (int i = 0; i < u; i++) {
        printf("%d: %d", unique[i], freq[i]);
        if (i != u - 1)
            printf(", ");
    }
    printf("}\n");

    return 0;
}

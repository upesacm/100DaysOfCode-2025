#include <stdio.h>

int main() {
    int n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    int fruits[n];
    printf("enter the elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &fruits[i]);
    }

    int max_len = 0, start = 0;
    int type1 = -1, type2 = -1;
    int last_type = -1, last_count = 0, curr_len = 0;

    for(int i = 0; i < n; i++) {
        if(fruits[i] == type1 || fruits[i] == type2) {
            curr_len++;
        } else {
            curr_len = last_count + 1;
        }

        if(fruits[i] == last_type) {
            last_count++;
        } else {
            last_count = 1;
        }

        if(fruits[i] != type1 && fruits[i] != type2) {
            type1 = last_type;
            type2 = fruits[i];
        }

        last_type = fruits[i];
        if(curr_len > max_len) {
            max_len = curr_len;
        }
    }

    printf("output-%d\n", max_len);
    return 0;
}

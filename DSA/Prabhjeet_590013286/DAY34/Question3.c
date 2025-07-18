#include <stdio.h>

int func(int x) {
    int l = 31, r = 0;
    while (((x >> l) & 1) == 0 && l > r) l--;
    while (r < l) {
        if (((x >> r) & 1) != ((x >> l) & 1)) return 0;
        r++;
        l--;
    }
    return 1;
}

int main() {
    int x;
    scanf("%d", &x);
    printf(func(x) ? "Yes\n" : "No\n");
    return 0;
}

#include <stdio.h>

#define SIZE 100
struct N { int v; int n; };
struct N a[SIZE];

int isPal(int h) {
    int vals[SIZE], c = 0, i = h;
    while (i != -1) {
        vals[c++] = a[i].v;
        i = a[i].n;
    }
    for (i = 0; i < c / 2; i++)
        if (vals[i] != vals[c - 1 - i]) return 0;
    return 1;
}

int main() {
    // Example: 1 -> 2 -> 1 -> 1 -> 2 -> 1
    int h = 0;
    int vals[] = {1, 2, 1, 1, 2, 1}, n = 6;
    for (int i = 0; i < n; i++) {
        a[i].v = vals[i];
        a[i].n = (i < n - 1) ? i + 1 : -1;
    }

    printf("%d\n", isPal(h));  // Output: 1 (true)
    return 0;
}

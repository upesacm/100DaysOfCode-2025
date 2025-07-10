#include <stdio.h>

#define SIZE 100
struct N { int v; int n; };
struct N a[SIZE], b[SIZE], r[SIZE];

int add(int x, int y) {
    int rx = -1, k = 0, c = 0;
    while (x != -1 || y != -1 || c) {
        int s = c;
        if (x != -1) { s += a[x].v; x = a[x].n; }
        if (y != -1) { s += b[y].v; y = b[y].n; }
        r[k].v = s % 10; c = s / 10;
        r[k].n = -1;
        if (rx == -1) rx = k;
        else r[k - 1].n = k;
        k++;
    }
    return rx;
}

void print(int h) {
    while (h != -1) {
        printf("%d ", r[h].v);
        h = r[h].n;
    }
    printf("\n");
}

int main() {
    // a: 4->5, b: 3->4->5 -> output: 3->9->0
    int va[] = {4, 5}, vb[] = {3, 4, 5}, n = 2, m = 3;
    for (int i = 0; i < n; i++) { a[i].v = va[i]; a[i].n = (i < n - 1) ? i + 1 : -1; }
    for (int i = 0; i < m; i++) { b[i].v = vb[i]; b[i].n = (i < m - 1) ? i + 1 : -1; }

    int rx = add(0, 0);
    print(rx);  // Output: 3 9 0
    return 0;
}

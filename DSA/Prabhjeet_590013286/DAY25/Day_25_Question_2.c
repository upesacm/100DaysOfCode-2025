#include <stdio.h>

#define SIZE 100
struct N { int v; int n; };
struct N a[SIZE], b[SIZE], r[SIZE];

int inter(int x, int y) {
    int rx = -1, i = x, j = y, k = 0;
    while (i != -1 && j != -1) {
        if (a[i].v == b[j].v) {
            r[k].v = a[i].v;
            r[k].n = -1;
            if (rx == -1) rx = k;
            else r[k - 1].n = k;
            k++;
            i = a[i].n; j = b[j].n;
        } else if (a[i].v < b[j].v) i = a[i].n;
        else j = b[j].n;
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
    // a: 1->2->3->4->6, b: 2->4->6->8
    int va[] = {1, 2, 3, 4, 6}, vb[] = {2, 4, 6, 8}, n = 5, m = 4;
    for (int i = 0; i < n; i++) {
        a[i].v = va[i]; a[i].n = (i < n - 1) ? i + 1 : -1;
    }
    for (int i = 0; i < m; i++) {
        b[i].v = vb[i]; b[i].n = (i < m - 1) ? i + 1 : -1;
    }

    int rx = inter(0, 0);
    print(rx);  // Output: 2 4 6
    return 0;
}

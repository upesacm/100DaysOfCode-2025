#include <stdio.h>

struct D {
    int v;
    int p, n; // previous and next indices
};

struct D d[100];

int del(int h, int pos) {
    int x = h;
    for (int i = 1; i < pos && x != -1; i++)
        x = d[x].n;

    if (x == -1) return h;

    int prev = d[x].p;
    int next = d[x].n;

    if (prev != -1) d[prev].n = next;
    else h = next;

    if (next != -1) d[next].p = prev;

    return h;
}

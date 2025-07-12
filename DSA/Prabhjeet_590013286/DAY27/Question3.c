struct S {
    int v;
    int n;
};

struct S s[100];

int rem(int h, int k) {
    int cnt = 1, x = h, prev = -1;
    while (x != -1) {
        if (cnt % k == 0) {
            if (prev != -1) s[prev].n = s[x].n;
            else h = s[x].n;
        } else {
            prev = x;
        }
        x = s[x].n;
        cnt++;
    }
    return h;
}

int rev(int h) {
    int x = h, last = -1;
    while (x != -1) {
        int temp = d[x].n;
        d[x].n = d[x].p;
        d[x].p = temp;
        last = x;
        x = temp;
    }
    return last;
}

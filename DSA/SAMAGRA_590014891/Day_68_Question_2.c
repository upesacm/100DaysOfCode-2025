#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int freq;
} Node;

int cmp(const void* a, const void* b) {
    return ((Node*)b)->freq - ((Node*)a)->freq;
}

char* rearrangeString(char* s) {
    int n = strlen(s);
    int count[256] = {0};
    for (int i = 0; i < n; i++) count[(int)s[i]]++;

    Node nodes[256];
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            nodes[size].ch = (char)i;
            nodes[size].freq = count[i];
            size++;
        }
    }

    qsort(nodes, size, sizeof(Node), cmp);

    char* res = (char*)malloc((n+1)*sizeof(char));
    res[n] = '\0';

    int idx = 0;
    for (int i = 0; i < size; i++) {
        while (nodes[i].freq > 0) {
            if (idx >= n) idx = 1;
            res[idx] = nodes[i].ch;
            idx += 2;
            nodes[i].freq--;
        }
    }

    for (int i = 1; i < n; i++) {
        if (res[i] == res[i-1]) {
            free(res);
            return "";
        }
    }
    return res;
}

int main() {
    char s1[] = "aab";
    printf("%s\n", rearrangeString(s1));

    char s2[] = "aaab";
    printf("%s\n", rearrangeString(s2));
    return 0;
}

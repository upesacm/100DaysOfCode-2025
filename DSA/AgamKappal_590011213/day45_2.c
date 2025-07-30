#include <stdio.h>
#define SIZE 100
int queue1[SIZE], queue2[SIZE];

int compareQueues(int n1, int n2) {
    if (n1 != n2) return 0;
    for (int i = 0; i < n1; i++) {
        if (queue1[i] != queue2[i]) return 0;
    }
    return 1;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &queue1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &queue2[i]);
    }
    if (compareQueues(n1, n2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int fruits[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &fruits[i]);

    int maxLen = 0, start = 0;
    int count[100001] = {0};
    int distinct = 0;

    for(int end = 0; end < n; end++) {
        if(count[fruits[end]] == 0)
            distinct++;
        count[fruits[end]]++;

        while(distinct > 2) {
            count[fruits[start]]--;
            if(count[fruits[start]] == 0)
                distinct--;
            start++;
        }

        if(end - start + 1 > maxLen)
            maxLen = end - start + 1;
    }

    printf("%d\n", maxLen);
    return 0;
}

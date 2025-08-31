#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0};
    int i, len, oddCount = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    for(i = 0; i < len; i++) {
        freq[(int)str[i]]++;
    }

    for(i = 0; i < 256; i++) {
        if(freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if(oddCount > 1) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}

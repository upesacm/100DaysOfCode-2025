#include <stdio.h>

int main() {
    int n;
    printf("Enter number of children: ");
    scanf("%d", &n);

    int ratings[n], candies[n];
    printf("Enter ratings:\n");
    for(int i=0;i<n;i++) scanf("%d",&ratings[i]);

    for(int i=0;i<n;i++) candies[i]=1;

    for(int i=1;i<n;i++) {
        if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
    }

    for(int i=n-2;i>=0;i--) {
        if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;
    }

    int total=0;
    for(int i=0;i<n;i++) total += candies[i];

    printf("Minimum candies required: %d\n", total);
    return 0;
}

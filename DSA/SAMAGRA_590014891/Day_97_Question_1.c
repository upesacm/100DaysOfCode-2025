#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[2005];
    if(scanf("%2000s", s)!=1) return 0;
    int n = strlen(s);
    int **isPal = malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        isPal[i]=calloc(n,sizeof(int));
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(s[i]==s[j] && (j-i<2 || isPal[i+1][j-1])) isPal[i][j]=1;
        }
    }
    int *cuts = malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        if(isPal[0][i]) { cuts[i]=0; continue; }
        int best = i;
        for(int j=0;j<i;j++){
            if(isPal[j+1][i] && cuts[j]+1 < best) best = cuts[j]+1;
        }
        cuts[i]=best;
    }
    printf("%d\n", n?cuts[n-1]:0);
    for(int i=0;i<n;i++) free(isPal[i]);
    free(isPal);
    free(cuts);
    return 0;
}

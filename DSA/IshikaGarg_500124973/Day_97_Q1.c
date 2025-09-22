#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int min(int a,int b){ return a<b?a:b; }

int minCutsPalindrome(char *s){
    int n = strlen(s);
    if(n==0) return 0;
    // isPal[i][j]
    char **isPal = (char**)malloc(n * sizeof(char*));
    for(int i=0;i<n;i++){
        isPal[i] = (char*)calloc(n, sizeof(char));
    }

    for(int len=1; len<=n; ++len){
        for(int i=0; i+len-1 < n; ++i){
            int j = i+len-1;
            if(s[i]==s[j]){
                if(len<=2) isPal[i][j] = 1;
                else isPal[i][j] = isPal[i+1][j-1];
            } else isPal[i][j] = 0;
        }
    }

    int *cuts = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        if(isPal[0][i]) { cuts[i]=0; continue; }
        int best = INT_MAX;
        for(int j=0;j<i;j++){
            if(isPal[j+1][i] && cuts[j]+1 < best) best = cuts[j]+1;
        }
        cuts[i] = best;
    }

    int ans = cuts[n-1];

    for(int i=0;i<n;i++) free(isPal[i]);
    free(isPal);
    free(cuts);

    return ans;
}

int main(){
    char s1[] = "aab";
    char s2[] = "a";
    printf("%s -> min cuts = %d\n", s1, minCutsPalindrome(s1)); // expected 1
    printf("%s -> min cuts = %d\n", s2, minCutsPalindrome(s2)); // expected 0
    // you can read input from stdin if needed
    return 0;
}


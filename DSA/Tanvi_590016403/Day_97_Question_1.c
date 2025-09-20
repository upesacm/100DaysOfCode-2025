/*
 * dp_palindrome_mcm.c
 * Single C program implementing three DP problems with a small interactive menu:
 * 1) Palindrome Partitioning (Minimum cuts)
 * 2) Longest Palindromic Subsequence (LPS length)
 * 3) Matrix Chain Multiplication (Minimum scalar multiplications)
 *
 * Compile: gcc -std=c99 -O2 dp_palindrome_mcm.c -o dp_dp
 * Run: ./dp_dp
 *
 * The program includes safe dynamic allocation, input helpers, and example runs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* --- Utility: 2D int allocation and free --- */
int **alloc_int_matrix(int n, int m) {
    int **a = (int **)malloc(n * sizeof(int *));
    if (!a) { perror("malloc"); exit(EXIT_FAILURE); }
    for (int i = 0; i < n; ++i) {
        a[i] = (int *)malloc(m * sizeof(int));
        if (!a[i]) { perror("malloc"); exit(EXIT_FAILURE); }
    }
    return a;
}

void free_int_matrix(int **a, int n) {
    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
}

char **alloc_char_matrix(int n, int m) {
    char **a = (char **)malloc(n * sizeof(char *));
    if (!a) { perror("malloc"); exit(EXIT_FAILURE); }
    for (int i = 0; i < n; ++i) {
        a[i] = (char *)malloc(m * sizeof(char));
        if (!a[i]) { perror("malloc"); exit(EXIT_FAILURE); }
    }
    return a;
}

void free_char_matrix(char **a, int n) {
    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
}

/* --------------------------------------------------------------------------
 * 1) Palindrome Partitioning (Min Cuts)
 * Precompute isPal[i][j] then compute cuts[i] => min cuts for prefix [0..i]
 * Returns minimum cuts for whole string.
 * -------------------------------------------------------------------------*/
int min_palindrome_cuts(const char *s) {
    int n = (int)strlen(s);
    if (n == 0) return 0;

    char **isPal = alloc_char_matrix(n, n); // use char 0/1
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) isPal[i][j] = 0;

    // Every single char is palindrome
    for (int i = 0; i < n; ++i) isPal[i][i] = 1;
    // Fill for lengths >= 2
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) isPal[i][j] = 1;
                else isPal[i][j] = isPal[i+1][j-1];
            } else {
                isPal[i][j] = 0;
            }
        }
    }

    int *cuts = (int *)malloc(n * sizeof(int));
    if (!cuts) { perror("malloc"); exit(EXIT_FAILURE); }

    for (int i = 0; i < n; ++i) {
        if (isPal[0][i]) {
            cuts[i] = 0; // whole prefix is palindrome
        } else {
            int minc = INT_MAX/2;
            for (int j = 0; j < i; ++j) {
                if (isPal[j+1][i]) {
                    if (cuts[j] + 1 < minc) minc = cuts[j] + 1;
                }
            }
            cuts[i] = minc;
        }
    }

    int result = cuts[n-1];
    free_char_matrix(isPal, n);
    free(cuts);
    return result;
}

/* --------------------------------------------------------------------------
 * 2) Longest Palindromic Subsequence (LPS length)
 * Classic DP where dp[i][j] is length of LPS in s[i..j]
 * -------------------------------------------------------------------------*/
int lps_length(const char *s) {
    int n = (int)strlen(s);
    if (n == 0) return 0;

    int **dp = alloc_int_matrix(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) dp[i][j] = 0;
    }

    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2) dp[i][j] = 2;
                else dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1];
            }
        }
    }

    int res = dp[0][n-1];
    free_int_matrix(dp, n);
    return res;
}

/* --------------------------------------------------------------------------
 * 3) Matrix Chain Multiplication (MCM)
 * dp[i][j] = min cost to multiply matrices i..j (1-based index for readability)
 * dims array has length m (number of matrices = m-1)
 * -------------------------------------------------------------------------*/
long long matrix_chain_multiplication(int *dims, int m) {
    // number of matrices = m-1
    int n = m - 1;
    if (n <= 0) return 0;

    // use long long to hold potentially large costs
    long long **dp = (long long **)malloc((n+1) * sizeof(long long *));
    if (!dp) { perror("malloc"); exit(EXIT_FAILURE); }
    for (int i = 0; i <= n; ++i) {
        dp[i] = (long long *)malloc((n+1) * sizeof(long long));
        if (!dp[i]) { perror("malloc"); exit(EXIT_FAILURE); }
    }

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dp[i][j] = 0;

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX/4;
            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k+1][j] + (long long)dims[i-1] * dims[k] * dims[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }

    long long result = dp[1][n];
    for (int i = 0; i <= n; ++i) free(dp[i]);
    free(dp);
    return result;
}

/* ------------------------ Helpers for user interaction ---------------------*/
void run_min_cuts_example() {
    char buffer[1005];
    printf("Enter string for palindrome partitioning (or a single word):\n");
    if (!scanf("%1004s", buffer)) return;
    int cuts = min_palindrome_cuts(buffer);
    printf("Minimum cuts needed: %d\n", cuts);
}

void run_lps_example() {
    char buffer[1005];
    printf("Enter string for longest palindromic subsequence:\n");
    if (!scanf("%1004s", buffer)) return;
    int len = lps_length(buffer);
    printf("Length of LPS: %d\n", len);
}

void run_mcm_example() {
    int m;
    printf("Enter number of dimensions (for p0 p1 ... pN) e.g. for 3 matrices enter 4:\n");
    if (scanf("%d", &m) != 1) return;
    if (m < 2) { printf("Need at least two dimensions (one matrix).\n"); return; }
    int *dims = (int *)malloc(m * sizeof(int));
    if (!dims) { perror("malloc"); exit(EXIT_FAILURE); }
    printf("Enter %d integers (space separated):\n", m);
    for (int i = 0; i < m; ++i) scanf("%d", &dims[i]);
    long long cost = matrix_chain_multiplication(dims, m);
    printf("Minimum number of scalar multiplications: %lld\n", cost);
    free(dims);
}

void run_examples_menu() {
    while (1) {
        int choice;
        printf("\nChoose problem to run:\n");
        printf("1) Palindrome Partitioning (Min cuts)\n");
        printf("2) Longest Palindromic Subsequence (LPS length)\n");
        printf("3) Matrix Chain Multiplication (Min cost)\n");
        printf("4) Run short built-in examples\");
        printf("\n0) Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) break;
        switch (choice) {
            case 1: run_min_cuts_example(); break;
            case 2: run_lps_example(); break;
            case 3: run_mcm_example(); break;
            case 4: {
                printf("\nBuilt-in example: \"aab\" for min cuts: Expected 1\n");
                printf("Result: %d\n", min_palindrome_cuts("aab"));
                printf("Built-in example: \"bbbab\" for LPS: Expected 4\n");
                printf("Result: %d\n", lps_length("bbbab"));
                int dims1[] = {1,2,3,4};
                printf("Built-in example: dims [1,2,3,4] (3 matrices) expected cost 18\n");
                printf("Result: %lld\n", matrix_chain_multiplication(dims1, 4));
            } break;
            default: printf("Invalid choice\n"); break;
        }
    }
}

int main(void) {
    printf("Dynamic Programming toolkit: Min cuts, LPS, MCM\n");
    run_examples_menu();
    printf("Exiting.\n");
    return 0;
}

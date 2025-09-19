def longestPalindromeSubseq(s: str) -> int:
    n = len(s)
    dp = [[0]*n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 1
    for length in range(2, n+1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = 2 + dp[i+1][j-1] if j - i > 1 else 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    return dp[0][n-1]

print("Input:")
s = "bbbab"
print("String:", s)
print("Output:")
print(longestPalindromeSubseq(s))

print("\nInput:")
s = "cbbd"
print("String:", s)
print("Output:")
print(longestPalindromeSubseq(s))

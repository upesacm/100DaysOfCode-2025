def lcs_length(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]


print("LCS('abcde','ace') =", lcs_length("abcde", "ace"))
print("LCS('abc','abc') =", lcs_length("abc", "abc"))
print("LCS('','abc') =", lcs_length("", "abc"))

"""
Answers:
1. The bug was using text1[i] and text2[j] instead of text1[i-1], text2[j-1].
2. This caused wrong comparisons and skipped the first characters.
"""

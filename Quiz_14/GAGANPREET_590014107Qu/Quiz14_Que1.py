# 1. Identify the specific indexing bug
# -- This incorrectly accesses text1[i] and text2[j], which are out of bounds when i or j equals the length of the string. Since Python uses 0-based indexing, valid indices range from 0 to len(text1) - 1 and 0 to len(text2) - 1.

# 2. Why this causes incorrect character comparison: 
# -- Because of the off-by-one error:
# text1[i] actually refers to the (i+1)th character, not the ith.
# So when i = 1, you're comparing text1[1] (second character) with text2[1] (second character), skipping the first characters entirely.
# This misalignment leads to incorrect LCS calculations, especially when the first characters are part of the subsequence.

def lcs_length(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:  # Corrected indexing
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]

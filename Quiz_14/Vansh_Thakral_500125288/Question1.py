def lcs_length(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:  # fixed indexing
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]


 # Specific Indexing Bug Inside the nested loop:
 # if text1[i] == text2[j]:
 # Bug: i and j range from 1 to m/n, but Python strings are 0-indexed.
 # Fix: Use i-1 and j-1:
 # if text1[i-1] == text2[j-1]:
 # Why?

# The DP table dp has dimensions (m+1) x (n+1) to handle the base case (empty prefix).
# The loop starts at 1 so that dp[i][j] represents the LCS of text1[0:i] and text2[0:j].
# Using text1[i] and text2[j] shifts every comparison one character ahead, causing:
# IndexError if i == m or j == n (last iteration tries to access a non-existent character).
# Even if it doesn’t crash (due to certain lengths), it compares the wrong characters, producing incorrect LCS lengths.


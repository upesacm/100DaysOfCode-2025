1. The specific indexing bug

In the code:
if text1[i] == text2[j]:
    dp[i][j] = dp[i-1][j-1] + 1


The indices i and j are off by one.
i runs from 1 → m
j runs from 1 → n

But in Python, string indices are 0-based.

So the comparisons should be:

if text1[i-1] == text2[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1

2. Why this causes incorrect character comparison

Because text1[i] and text2[j] skip the first character of each string and may even try to access out-of-range indices at the end.

For example:

For text1 = "abcde" and text2 = "ace"

On the first iteration, i = 1, j = 1

The code compares text1[1] = 'b' with text2[1] = 'c'

But it should compare text1[0] = 'a' with text2[0] = 'a'.

This shifts all comparisons and breaks the LCS logic.

 Fixed version:

def lcs_length(text1, text2):
    m, n = len(text1), len(text2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:  # FIXED indexing
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]

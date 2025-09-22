def lcs_length(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i] == text2[j]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]

#The indexing bug: 
#The code incorrectly indexes the characters of text1 and text2 using i and j directly.
#Since strings are 0-indexed, but the loops run from 1, it should use text1[i-1] and text2[j-1].
#
#this causes incorrect character comparison:
#text1[i] and text2[j] will either compare the wrong characters (offset by +1),
#or cause IndexError if i == len(text1) or j == len(text2), resulting in failed tests or wrong matches.

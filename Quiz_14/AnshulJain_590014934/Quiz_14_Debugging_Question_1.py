def lcs_length(text1, text2):
    m, n = len(text1), len(text2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:  
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]


# Test cases that reveal the bug:
test1 = lcs_length("abcde", "ace")
print(f"LCS('abcde', 'ace'): {test1}")  # Should be 3


test2 = lcs_length("abc", "abc")  
print(f"LCS('abc', 'abc'): {test2}")   # Should be 3


test3 = lcs_length("", "abc")
print(f"LCS('', 'abc'): {test3}")      # Should be 0

# task answer:
#1) The specific indexing bug is that the code uses text1[i] and text2[j] instead of text1[i - 1] and text2[j - 1] 
# while comparing characters.

# 2)This causes incorrect character comparison because the loop indices i and j start from 1 (to account for the DP table indexing), but string indices are zero-based. Using text1[i] or text2[j] accesses one position ahead, causing an index out of range or wrong character references, so comparisons do not match expected characters in the strings. This leads to incorrect longest common subsequence calculation.
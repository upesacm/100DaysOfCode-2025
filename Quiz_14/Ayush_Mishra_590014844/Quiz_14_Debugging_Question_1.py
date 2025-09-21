def lcs_length(text1, text2):
    m, n = len(text1), len(text2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # BUG FIX: must use i-1 and j-1 here
            # Because Python strings are 0-based, while our DP table is 1-based.
            # If we use text1[i] and text2[j], we skip the first character
            # and compare the wrong ones (off-by-one error).
            if text1[i-1] == text2[j-1]:  
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]


# Test cases
test1 = lcs_length("abcde", "ace")
print(f"LCS('abcde', 'ace'): {test1}")   # Expected: 3

test2 = lcs_length("abc", "abc")
print(f"LCS('abc', 'abc'): {test2}")     # Expected: 3

test3 = lcs_length("", "abc")
print(f"LCS('', 'abc'): {test3}")        # Expected: 0

def lcs_length(text1, text2):
    m, n = len(text1), len(text2)

    # DP table with extra row & column for base case initialization
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # BUG: originally compared text1[i] == text2[j]
            # That is incorrect because dp table has +1 padding,
            # so the correct character index is i-1 and j-1.
            if text1[i - 1] == text2[j - 1]:  
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]


# Test cases that reveal the bug and confirm fix:

test1 = lcs_length("abcde", "ace")
print(f"LCS('abcde', 'ace'): {test1}")  
# Expected: 3
# Original buggy code compared text1[i] with text2[j],
# which skipped the first character and caused wrong results.

test2 = lcs_length("abc", "abc")  
print(f"LCS('abc', 'abc'): {test2}")   
# Expected: 3
# Buggy version might return 2 because of off-by-one indexing.

test3 = lcs_length("", "abc")
print(f"LCS('', 'abc'): {test3}")      
# Expected: 0
# Works correctly since empty string handled by base case.

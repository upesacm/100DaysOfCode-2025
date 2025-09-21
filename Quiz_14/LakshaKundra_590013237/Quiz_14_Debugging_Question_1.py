#answer 1
#The main bug is here:
#if text1[i] == text2[j]:
#correct is:
#if text1[i-1] == text2[j-1]:

#answer 2
#The first characters are never compared correctly, because text1[1] is the second character.
#The last iteration may raise an IndexError if i == len(text1) or j == len(text2).

#correct code
def lcs_length(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]

test1 = lcs_length("abcde", "ace")
print(f"LCS('abcde', 'ace'): {test1}")
test2 = lcs_length("abc", "abc")
print(f"LCS('abc', 'abc'): {test2}")
test3 = lcs_length("", "abc")
print(f"LCS('', 'abc'): {test3}")

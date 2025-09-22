def lcs_length(text1, text2):
    m, n = len(text1), len(text2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # BUG 1: Indexing bug - text1[i] and text2[j] access indices 1,2,3,...m and 1,2,3,...n
            # But Python strings are 0-indexed, so this compares characters at positions 1,2,3,... 
            # This causes us to miss the first character of both strings entirely!
            # 
            # Task 1: The specific indexing bug is using text1[i] and text2[j] instead of text1[i-1] and text2[j-1]
            # 
            # Task 2: This causes incorrect character comparison because:
            # - For i=1, text1[1] = second character (index 1), but we want first character (index 0)
            # - For i=m, text1[m] = character after last character (would cause IndexError if not caught)
            # - We effectively skip the first character of both strings in comparison
            # - The DP logic is correct but compares wrong characters, leading to incorrect subsequence matching
            
            if text1[i-1] == text2[j-1]:  # FIXED: Use i-1 and j-1 for 0-based indexing
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]

# Test cases that reveal the bug:
test1 = lcs_length("abcde", "ace")
print(f"LCS('abcde', 'ace'): {test1}")  # Now correctly returns 3 (characters 'a','c','e')

test2 = lcs_length("abc", "abc")  
print(f"LCS('abc', 'abc'): {test2}")   # Now correctly returns 3 (all characters match)

test3 = lcs_length("", "abc")
print(f"LCS('', 'abc'): {test3}")      # Correctly returns 0 (empty string has no subsequence)

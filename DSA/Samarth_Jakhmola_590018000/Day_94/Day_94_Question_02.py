def longest_common_subsequence(string1, string2):
    n, m = len(string1), len(string2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if string1[i - 1] == string2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n][m]  # LCS (longest common subsequence) length

string1 = input("Enter the first string : ")
string2 = input("Enter the second string : ")
print(longest_common_subsequence(string1, string2))

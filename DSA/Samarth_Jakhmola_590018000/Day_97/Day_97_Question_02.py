def longest_palindromic_subsequence(string):
    n = len(string)

    # Step 1 : Create a 2D DP table
    dp = [[0] * n for _ in range(n)]

    # Step 2 : Every single character is a palindrome of length 1
    for i in range(n):
        dp[i][i] = 1

    # Step 3 : Fill DP table for substrings of increasing length
    for length in range(2, n + 1):  # substring length
        for i in range(n - length + 1):
            j = i + length - 1  # right boundary
            if string[i] == string[j]:
                if length == 2:
                    dp[i][j] = 2  # two equal chars
                else:
                    dp[i][j] = 2 + dp[i + 1][j - 1]  # expand palindrome
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])  # skip either end
                
    # Final answer : LPS length for full string
    return dp[0][n - 1]

string = input("Enter the string : ")
print(longest_palindromic_subsequence(string))

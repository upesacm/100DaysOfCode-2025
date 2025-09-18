n = int(input("Enter N: "))
dp = [0] * (n + 1)
dp[0] = 1
if n > 0:
    dp[1] = 1
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]
print("Output:")
print(dp[n])

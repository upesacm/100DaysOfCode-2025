def matrix_chain_multiplication(dimensions):
    n = len(dimensions) - 1  # number of matrices
    dp = [[0] * (n + 1) for _ in range(n + 1)]  # dp[i][j] = min cost for multiplying Ai..Aj

    # Fill DP for increasing chain lengths
    for length in range(2, n + 1):  # chain length
        for i in range(1, n - length + 2):  # starting index
            j = i + length - 1  # ending index
            dp[i][j] = float('inf')  # initialize with infinity

            # Try all possible split points
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j]
                if cost < dp[i][j]:
                    dp[i][j] = cost

    return dp[1][n]
    
dimensions = list(map(int, input("Enter the matrix dimensions, separated by spaces : ").split()))
print(matrix_chain_multiplication(dimensions))

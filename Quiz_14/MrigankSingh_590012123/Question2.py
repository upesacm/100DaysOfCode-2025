def knapsack_01(weights, values, capacity):
    n = len(weights)

    # Create DP table
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Fill DP table
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            # Don't include current item
            dp[i][w] = dp[i-1][w]

            # BUG 1: Indexing bug - weights[i] and values[i] access indices 1,2,3,...n
            # But Python lists are 0-indexed, so this accesses the second element when i=1
            # This causes us to skip the first item entirely and access out of bounds for the last item!
            # 
            # Task 1: The indexing bug is using weights[i] and values[i] instead of weights[i-1] and values[i-1]
            # 
            # Task 2: What happens with out-of-bounds indices:
            # - When i=1: weights[1] = second item (index 1), skips first item (index 0)
            # - When i=n: weights[n] = IndexError! (tries to access element after last element)
            # - The function would crash with IndexError on the last iteration
            # 
            # Task 3: Correct indexing should be weights[i-1] and values[i-1] to match 0-based Python indexing
            
            if weights[i-1] <= w:  # FIXED: Use i-1 for 0-based indexing
                include_value = dp[i-1][w - weights[i-1]] + values[i-1]  # FIXED: Use i-1 here too
                dp[i][w] = max(dp[i][w], include_value)

    return dp[n][capacity]

# Test case:
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]  
capacity = 7

result = knapsack_01(weights, values, capacity)
print(f"Maximum value: {result}")  # Now correctly returns 9 (items with weights 3+4, values 4+5)

# Edge case:
weights2 = [2, 3, 4, 5]
values2 = [3, 4, 5, 6]
capacity2 = 5

result2 = knapsack_01(weights2, values2, capacity2)
print(f"Edge case result: {result2}")  # Now correctly returns 4 (item with weight 3, value 4)

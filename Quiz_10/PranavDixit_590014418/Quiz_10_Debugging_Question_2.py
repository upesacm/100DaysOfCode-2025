def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    for i in range(n):
        ratio = values[i] / weights[i]   # value per weight (important for greedy choice)
        items.append((values[i], weights[i], ratio))

    # ---- BUG FIX ----
    # The given code was sorting by value only (x[0]),
    # which is WRONG for fractional knapsack.
    # We need to sort by ratio (value/weight) in descending order.
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0
    current_weight = 0

    for value, weight, ratio in items:
        if current_weight + weight <= capacity:
            # take the full item
            current_weight += weight
            total_value += value
        else:
            # take only the fraction that fits
            remaining_capacity = capacity - current_weight
            fraction = remaining_capacity / weight
            total_value += value * fraction
            break   # no more capacity left

    return total_value


# test case
weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
result = fractional_knapsack(weights, values, capacity)
print("Maximum value:", result)

"""
--------------------------
ANSWERS TO TASKS:

1) Identify the incorrect sorting criteria:
   -> The code was sorting by "value" (x[0]) only.
   -> This is wrong because a high-value item with a very high weight
      might not be the best choice.

2) Why sorting by value instead of value/weight ratio is wrong:
   -> Example: Item with value=120, weight=60 vs Item with value=60, weight=10.
      The first has ratio 2, the second has ratio 6.
      Clearly the second item gives more "value per unit weight".
   -> Sorting only by value ignores this fact and leads to a suboptimal solution.

3) What should be the correct sorting approach:
   -> Sort the items by "value/weight ratio" in descending order.
   -> Always pick the item with the highest ratio first (greedy method).
--------------------------
"""

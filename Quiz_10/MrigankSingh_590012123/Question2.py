def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((values[i], weights[i], ratio))

    # BUG FIXED: Changed sorting criteria from value to value/weight ratio
    # Original bug: items.sort(key=lambda x: x[0], reverse=True) - sorted by value
    # Why the bug caused suboptimal results:
    #   Sorting by value alone prioritizes high-value items regardless of their weight,
    #   which may lead to inefficient use of capacity. A lighter item with lower absolute value
    #   but higher value-to-weight ratio might be more beneficial.
    # Correct approach: Sort by value/weight ratio in descending order to always select
    # the most efficient items first, maximizing value per unit of weight.
    items.sort(key=lambda x: x[2], reverse=True)  # Correct: sort by ratio

    total_value = 0
    current_weight = 0

    for value, weight, ratio in items:
        if current_weight + weight <= capacity:
            current_weight += weight
            total_value += value
        else:
            remaining_capacity = capacity - current_weight
            fraction = remaining_capacity / weight
            total_value += value * fraction
            break

    return total_value


# Test case:
weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
result = fractional_knapsack(weights, values, capacity)
print(f"Maximum value: {result}")  # Expected: 240.0

def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((values[i], weights[i], ratio))

    items.sort(key=lambda x: x[2], reverse=True)

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


weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
result = fractional_knapsack(weights, values, capacity)
print(f"Maximum value: {result}")

# 1. The incorrect sorting criterion is sorting by value instead of value/weight ratio.
# 2. Sorting by value causes suboptimal results because a high-value but heavy item may prevent taking smaller high-ratio items that maximize total value.
# 3. The correct sorting approach is to sort items in descending order of value/weight ratio.

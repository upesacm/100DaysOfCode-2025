def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    # Create list of (value, weight, value/weight ratio)
    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((values[i], weights[i], ratio))

    # ✅ Sort by value-to-weight ratio in descending order
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0
    current_weight = 0

    for value, weight, ratio in items:
        if current_weight + weight <= capacity:
            current_weight += weight
            total_value += value
        else:
            remaining_capacity = capacity - current_weight
            total_value += ratio * remaining_capacity
            break

    return total_value

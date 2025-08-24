def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    items = []

    # Store items as (value, weight, ratio)
    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((values[i], weights[i], ratio))

    # ✅ FIX: Sort by ratio (value/weight), not just value
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0
    current_weight = 0

    for value, weight, ratio in items:
        if current_weight + weight <= capacity:
            # take full item
            current_weight += weight
            total_value += value
        else:
            # take fractional part
            remaining_capacity = capacity - current_weight
            total_value += value * (remaining_capacity / weight)
            break

    return total_value

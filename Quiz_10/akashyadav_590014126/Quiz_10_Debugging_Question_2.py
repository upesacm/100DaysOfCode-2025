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

#The bug was sorting by total value instead of value-to-weight ratio.
#Sort items in descending order of (value / weight) ratio. This ensures we always pick the most "profitable per unit weight" first.
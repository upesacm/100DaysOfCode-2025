def fractional_knapsack(weights, values, capacity):
    items = sorted(zip(weights, values), key=lambda x: x[1] / x[0], reverse=True)
    total_value = 0
    remaining_capacity = capacity

    for w, v in items:
        if remaining_capacity >= w:
            total_value += v
            remaining_capacity -= w
        else:
            fraction = remaining_capacity / w
            total_value += v * fraction
            break

    return total_value

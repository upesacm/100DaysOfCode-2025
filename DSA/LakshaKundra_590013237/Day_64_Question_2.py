def fractional_knapsack(weights, values, capacity):
    items = sorted(zip(weights, values), key=lambda x: x[1]/x[0], reverse=True)
    total_value = 0
    for w, v in items:
        if capacity >= w:
            total_value += v
            capacity -= w
        else:
            total_value += v * (capacity / w)
            break
    return total_value

print(fractional_knapsack([10, 20, 30], [60, 100, 120], 50))
print(fractional_knapsack([5, 10], [50, 60], 10))

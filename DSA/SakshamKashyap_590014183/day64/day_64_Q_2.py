def fractional_knapsack(weights, values, capacity):
    if len(weights) != len(values):
        return 0.0
    
    # Create list of (value, weight, ratio)
    items = sorted(zip(values, weights), key=lambda x: x / x, reverse=True)
    
    total_value = 0.0
    remaining_capacity = capacity
    
    for value, weight in items:
        if remaining_capacity >= weight:
            # Take the whole item
            total_value += value
            remaining_capacity -= weight
        else:
            # Take fraction
            fraction = remaining_capacity / weight
            total_value += value * fraction
            remaining_capacity = 0
            break  # Knapsack is full
    
    return total_value

# Example 1
weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
print(fractional_knapsack(weights, values, capacity))  # Output: 240.0

# Example 2
weights = [5, 10]
values = [50, 60]
capacity = 10
print(fractional_knapsack(weights, values, capacity))  # Output: 80.0

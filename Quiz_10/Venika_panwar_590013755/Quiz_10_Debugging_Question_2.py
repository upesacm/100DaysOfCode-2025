def fractional_knapsack(weights, values, capacity):
    """
    Solves the fractional knapsack problem using a greedy approach.
    Fix: Sort by value-to-weight ratio (not value) for optimal results.
    """
    n = len(weights)
    # Each item: (value, weight, value-to-weight ratio)
    items = [(values[i], weights[i], values[i] / weights[i]) for i in range(n)]

    # Correct: Sort items by value-to-weight ratio in descending order
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0
    current_weight = 0

    for value, weight, ratio in items:
        if current_weight + weight <= capacity:
            # If the whole item fits, take it all
            total_value += value
            current_weight += weight
        else:
            # Otherwise, take the fraction that fits
            remaining_capacity = capacity - current_weight
            total_value += ratio * remaining_capacity
            break

    return total_value

# Example/test case:
weights = [10, 20, 30]
values  = [60, 100, 120]
capacity = 50
result = fractional_knapsack(weights, values, capacity)
print(f"Maximum value in knapsack: {result}")  # Output: 240.0

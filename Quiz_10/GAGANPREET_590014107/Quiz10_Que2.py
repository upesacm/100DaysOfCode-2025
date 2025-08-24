# 1. Identify the incorrect sorting criterio
# -- items.sort(key=lambda x: x[0], reverse=True)
#     This line sorts items by total value, not by value-to-weight ratio, which is the key metric in fractional knapsack problems.

# 2. Explain why sorting by value  instead of value/weight ratio.
# -- Sorting by raw value prioritizes items with high total worth, regardless of how much weight they consume. This can lead to inefficient use of capacity. For example:
#   - An item with value 100 and weight 50 has a ratio of 2.
#   - An item with value 60 and weight 10 has a ratio of 6.

# 3. What should be the correct sorting approach? 
# You should sort items by value-to-weight ratio in descending order.

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
            total_value += ratio * remaining_capacity
            break

    return total_value

def fractional_knapsack(weights, values, capacity):
    items = sorted(zip(weights, values), key=lambda x: x[1]/x[0], reverse=True)
    
    total_value = 0.0
    for weight, value in items:
        if capacity == 0:
            break
        if weight <= capacity:
            total_value += value
            capacity -= weight
        else:
            total_value += value * (capacity / weight)
            capacity = 0
    
    return total_value

# Example 
weights = [5, 10]
values = [50, 60]
capacity = 10
print(fractional_knapsack(weights, values, capacity)) 

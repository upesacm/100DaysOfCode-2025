def fractional_knapsack(weights, values, capacity):
    # Pair each item with ratio, weight and value.
    items = [(values[i]/weights[i], weights[i], values[i]) for i in range(len(weights))]

    # Sort by descending ratios.
    items.sort(key = lambda x : x[0], reverse = True)

    total_value = 0.0
    for ratio, wt, val in items:
        if capacity >= wt:   # Take full item 
            capacity -= wt
            total_value += val
        else:    # Take fraction of the item
            total_value += ratio * capacity
            break

    return total_value

try:
    weights = list(map(int, input("Enter the weights of the items separated by spaces : ").split()))
    values = list(map(int, input("Enter the values of the separated by spaces : ").split()))
    capacity = int(input("Enter the capacity : "))
    print(fractional_knapsack(weights, values, capacity))
except:
    print("Invalid input. Please try with a valid input.") 
